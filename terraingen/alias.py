# Copyright (c) Mathias Kaerlev 2013.
#
# This file is part of cuwo.
#
# cuwo is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# cuwo is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with cuwo.  If not, see <http://www.gnu.org/licenses/>.

function_alias = {
    0x4C8580: 'initialize_manager',
    0x4D7FA0: 'initialize_seed',
    0x5183D0: 'generator_func'
}

import_alias = {
    '??2@YAPAXI@Z': 'new_func',
    ('ws2_32', 115L): 'WSAStartup',
    '??3@YAXPAX@Z': 'delete_func',
    '??0exception@std@@QAE@ABQBDH@Z': 'exception_ctor_noalloc',
    '??0exception@std@@QAE@ABQBD@Z': 'exception_ctor',
    '??0bad_cast@std@@QAE@PBD@Z': 'bad_cast_ctor_charptr',
    '??_V@YAXPAX@Z': 'delete_arr_func',
    '??0?$basic_istream@DU?$char_traits@D@std@@@std@@QAE@PAV?$basic_streambuf@DU?$char_traits@D@std@@@1@_N@Z':
        'basic_istream_char_ctor',
    '??0?$basic_streambuf@DU?$char_traits@D@std@@@std@@IAE@XZ':
        'basic_streambuf_char_ctor',
    '?_Init@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IAEXXZ':
        'basic_streambuf_char__Init_empty',
    '?_Fiopen@std@@YAPAU_iobuf@@PBDHH@Z': '_Fiopen',
    '?setstate@?$basic_ios@DU?$char_traits@D@std@@@std@@QAEXH_N@Z':
        'basic_ios_char_setstate_reraise',
    '??1?$basic_streambuf@DU?$char_traits@D@std@@@std@@UAE@XZ':
        'basic_streambuf_char_dtor',
    '??1?$basic_istream@DU?$char_traits@D@std@@@std@@UAE@XZ':
        'basic_istream_char_dtor',
    '??1?$basic_ios@DU?$char_traits@D@std@@@std@@UAE@XZ':
        'basic_ios_char_dtor',
    '??5?$basic_istream@DU?$char_traits@D@std@@@std@@QAEAAV01@AAH@Z':
        'basic_istream_char_read_int',
    '??0?$basic_ios@DU?$char_traits@D@std@@@std@@IAE@XZ':
        'basic_ios_char_ctor',
    '??0?$basic_iostream@DU?$char_traits@D@std@@@std@@QAE@PAV?$basic_streambuf@DU?$char_traits@D@std@@@1@@Z':
        'basic_iostream_char_ctor',
    '??6?$basic_ostream@DU?$char_traits@D@std@@@std@@QAEAAV01@H@Z':
        'basic_ostream_char_print_int',
    '?sputn@?$basic_streambuf@DU?$char_traits@D@std@@@std@@QAE_JPBD_J@Z':
        'basic_streambuf_char_sputn',
    '?uncaught_exception@std@@YA_NXZ': '__uncaught_exception',
    '?_Osfx@?$basic_ostream@DU?$char_traits@D@std@@@std@@QAEXXZ':
        'basic_ostream_char__Osfx',
    '?setg@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IAEXPAD00@Z':
        'basic_streambuf_char_setg',
    '??1?$basic_iostream@DU?$char_traits@D@std@@@std@@UAE@XZ':
        'basic_iostream_char_dtor',
    '?_Ios_base_dtor@ios_base@std@@CAXPAV12@@Z': 'ios_base_Ios_base_dtor'
}

function_enders = set([
    '_Xlength_errorstdYAXPBDZ_imp'
])