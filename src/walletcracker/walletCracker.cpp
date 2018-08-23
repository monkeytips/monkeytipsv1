// Copyright (c) 2018, The TurtleCoin Developers
//
// Please see the included LICENSE file for more information.



//////////////////////////////////////
#include <walletcracker/walletCracker.h>
//////////////////////////////////////

#include <CryptoNoteCore/Currency.h>

#include <Logging/FileLogger.h>
#include <Logging/LoggerManager.h>

#include <NodeRpcProxy/NodeRpcProxy.h>

int main()
{
    /* Logging to a black hole... */
    Logging::LoggerManager logManager;
    Logging::LoggerRef logger(logManager, "zedwallet");

    /* Currency contains our coin parameters, such as decimal places, supply */
    CryptoNote::Currency currency
        = CryptoNote::CurrencyBuilder(logManager).currency();

    System::Dispatcher localDispatcher;
    System::Dispatcher *dispatcher = &localDispatcher;

    /* Our connection to monkeytipsd */
    std::unique_ptr<CryptoNote::INode> node(
        new CryptoNote::NodeRpcProxy("getbent", 666,
                                     logger.getLogger()));

    /* Create the wallet instance */
    CryptoNote::WalletGreen wallet(*dispatcher, currency, *node,
                                   logger.getLogger());

    /* Run the interactive wallet interface */
    bruteForce(wallet);
}

void bruteForce(CryptoNote::WalletGreen &wallet)
{
    std::string walletFileName = getExistingWalletFileName();

    std::string charSet = getCharSet();

    std::string password = bruteForce(wallet, walletFileName, charSet);

    if (password == "")
    {
        std::cout << std::endl
                  << "Your wallet has no password! I.e., it is the empty "
                  << "string \"\"" << std::endl;
    }
    else
    {
        std::cout << std::endl
                  << "Your wallet password is: "
                  << password << std::endl;
    }
}

std::string getCharSet()
{
    std::string simpleCharSet = "abcdefghijklmnopqrstuvwxyz";

    std::string mediumCharSet = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::string fullCharSet = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

    while (true)
    {
        std::string charSet;

        std::cout << "What character set do you want to use?"
                  << std::endl
                  << "A smaller char set will make cracking faster."
                  << std::endl
                  << "1 - Basic: a-z"
                  << std::endl
                  << "2 - Medium: a-z, A-Z, 0-9"
                  << std::endl
                  << "3 - Full: a-z, A-Z, 0-9, !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"
                  << std::endl
                  << "Enter selection (1 - 3): ";

        std::getline(std::cin, charSet);

        if (charSet == "1")
        {
            return simpleCharSet;
        }
        else if (charSet == "2")
        {
            return mediumCharSet;
        }
        else if (charSet == "3")
        {
            return fullCharSet;
        }
        else
        {
            std::cout << "Bad input, expected a number from 1 to 3" << std::endl;
        }
    }
}

std::string bruteForce(CryptoNote::WalletGreen &wallet, std::string filename,
                       std::string charSet)
{
    std::cout << std::endl
              << "If your password is anything more than 3 characters, this "
              << "will take a long fucking time" << std::endl << std::endl;

    for (int i = 0; i < 100; i++)
    {
        std::cout << "Trying passwords of length " << i << std::endl;

        std::string s = charSet;

        do
        {
            std::string password = std::string(s.begin(), s.begin() + i);

            if (wallet.crack(filename, password))
            {
                return password;
            }
        }
        while(next_combination(s.begin(), s.begin() + i, s.end()));
    }

    return "Failed to find password, get fucked";
}

std::string getExistingWalletFileName()
{
    bool initial = true;

    std::string walletName;

    while (true)
    {
        std::cout << "What is the name of the wallet file you want to crack?: ";
        std::getline(std::cin, walletName);

        std::string walletFileName = walletName + ".wallet";

        if (walletName == "")
        {
            std::cout << "Wallet name can't be blank! Try again."
                      << std::endl;
        }
        /* Allow people to enter wallet name with or without file extension */
        else if (boost::filesystem::exists(walletName))
        {
            return walletName;
        }
        else if (boost::filesystem::exists(walletFileName))
        {
            return walletFileName;
        }
        else
        {
            std::cout << "File doesn't exist, try again." << std::endl;
        }
    }
}
