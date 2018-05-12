// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <initializer_list>

namespace CryptoNote {
struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = {  
 { 1000, "7dfeccfd5af2b48dcceff05516ffc150b4179d7d5d0a8edd7f8dbb3276bd5fba" },
 { 1755, "548a574df54b9c0303635c2191ddd912131721597792d028578f9ef55a8e682e" },
 { 2966, "bac75a7fbe416ed33cb206f058a657ff767844207ae2ba0b6feecf062261f640" },
 { 3911, "793fc5af99ea4ea41c2b69037543c534c95d7365eda79abb09bf6351412c757f" },
 { 4307, "8e846b9765b9075be9e4d8d7162186c5e8fee77658f7aab35f075d53ec86b455" },
 { 5730, "2063405a8e4a17e8bed3e08cefd225337076bc444b6155d8f77abbb5114e8e2c" },
 { 6550, "faf02b92d0d87676f19cd1333552f0924e974ff99d5153ebac662433bab2e1bb" },
 { 7800, "5548824a26bad00205a50245338d4e3fa3e40e34968d291b3e99d1bb6cd5bfa4" },
 { 9485, "de106c95b3ddc49aac997992ec6aa8c18f89fedc5947a3e6a2e47e47a3fa033d" },
 { 9710, "dff92af071ec0e388fc57e46599551d9cf885aa88055d3384fb10a7e4b8e40f4" },
 { 15894, "51999fe53c445d131790439000940279df797ddd779049f5776bb7a01f576e5d" },
 { 22500, "ad7c84ac33fb8cf0aa914be95be26f907f91493efa94285621efc2985cae560a" },
 { 27850, "2b368d553dbf373c0916c17368afd5f7da77c332ce990597f985ccb9215962e9" },
 { 33050, "e309a7dba6413ce8b2ef47c86115f9c2a45c47870296587f07ddd143441c63d4" },
 { 36905, "07f894174d20da58e583e8cb28e7ffc2705209531ffdec380de1e8647c73fd09" },
 { 40175, "322e6b97eb53c70a67c379a3e2094c896e932301deed57cb2c898538f492e00b" }
};
}
