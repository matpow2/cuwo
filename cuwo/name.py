# Copyright (c) Mathias Kaerlev 2013-2014.
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

# borrowed from
# https://github.com/DatZach/CharacterEditor/blob/master/Source/Character/
# NameGenerator.cs

PIECES = {
    -1: ([
        'Kro', 'Aru', 'As', 'Ge', 'Kur', 'Lugo', 'Iko', 'Liku', 'Tero', 'Var',
        'An', 'The', 'Ga', 'Lan', 'Dura', 'Dama', 'Se', 'Thal', 'Nar', 'San'
    ], [
        'no', 'mi', 'la', 'sel', 'ron', 'ion', 'kor', 'lon', 'rok', 'tar',
        'den', 'gar', 'dar', 'dara', 'lan', 'ka', 'gor', 'rior', 'ria', 'mor'
    ]),
    0: (['El', 'Li', 'Dri', 'Elan', 'Le', 'Ly', 'A', 'Tho', 'Da', 'Les'], [
        'ric', 'kun', 'zic', 'dor', 'las', 'sander', 'reon', 'reas', 'lundra',
        'andor'
    ]),
    1: (['Ar', 'A', 'Si', 'Mer', 'Lu', 'Ari', 'Su', 'Sira', 'Hia', 'Li'], [
        'weya', 'luna', 'laya', 'leya', 'ma', 'lia', 'matra', 'vy', 'zyna',
        'ly'
    ]),
    2: (['De', 'Ro', 'As', 'Ge', 'An', 'Pat', 'Wolf', 'Ale', 'Mi', 'Ben'], [
        'rek', 'man', 'gram', 'rald', 'rick', 'ram', 'sander', 'kal', 'ton',
        'ny'
    ]),
    3: (['Sa', 'Jen', 'Kla', 'Mi', 'La', 'Auri', 'Mela', 'Alu', 'Ve', 'Est'],
        ['rah', 'ny', 'ria', 'elle', 'na', 'ga', 'ma', 'riana', 'rona',
         'una']),
    4: (['Gra', 'Xe', 'Ur', 'Bel', 'Chu', 'Ki', 'Go', 'Zim', 'Kubo', 'Raz'],
        ['zic', 'nax', 'tik', 'tuk', 'ruk', 'bo', 'rix', 'mi', 'tok', 'nor']),
    5: (['Kur', 'Xe', 'Ki', 'Am', 'Zifa', 'Zu', 'Ma', 'Chi', 'Zi', 'Mia'],
        ['ra', 'lia', 'bi', 'ba', 'ly', 'ki', 'bara', 'mi', 'zy', 'xa']),
    7:
    (['Cho', 'Zer', 'Kaz', 'Kraz', 'Zel', 'Drak', 'Lo', 'Raz', 'Spi', 'Zen'],
     ['rux', 'rek', 'zic', 'tac', 'mec', 'kor', 'rax', 'zor', 'ro', 'go']),
    8: (['Zi', 'Zer', 'Az', 'Ki', 'Iza', 'Drak', 'Li', 'May', 'Spi', 'Zan'],
        ['rya', 'ri', 'zia', 'ki', 'mah', 'ira', 'maya', 'ana', 'ra', 'ya']),
    9:
    (['Tor', 'Gem', 'Bar', 'Me', 'As', 'Tem', 'Arak', 'Ur', 'Grim', 'Xor'],
     ['lox', 'bart', 'kor', 'thos', 'kun', 'bur', 'thor', 'lok', 'li', 'bor']),
    10: ([
        'Mum', 'Grun', 'Brun', 'Hei', 'Mo', 'Hil', 'Ur', 'Lum', 'Grim', 'Xor'
    ], ['pie', 'hild', 'di', 'muna', 'ki', 'trud', 'sa', 'axa', 'ira', 'ika']),
    11: (['Uz', 'Ur', 'Chu', 'Ku', 'Mor', 'Ura', 'Ak', 'Ur', 'Or', 'Gor'], [
        'ku', 'ruk', 'muk', 'thak', 'dok', 'tor', 'rorok', 'chak', 'kaz',
        'rack'
    ]),
    12: (['Uz', 'Ur', 'Chu', 'Ku', 'Mor', 'Ura', 'Ak', 'Ur', 'Or', 'Gor'], [
        'ka', 'rua', 'mua', 'thara', 'daka', 'tah', 'rorah', 'chaka', 'kaya',
        'rana'
    ]),
    13: ([
        'Qua', 'Rib', 'Quib', 'Zib', 'Il', 'Wok', 'Wib', 'Moko', 'Sli', 'Bul'
    ], ['rik', 'bit', 'ble', 'bik', 'wak', 'wok', 'wib', 'luk', 'mey', 'bak']),
    14:
    (['Qua', 'Rib', 'Quib', 'Zib', 'Il', 'Wok', 'Wib', 'Moko', 'Sli', 'Bul'], [
        'ria', 'bia', 'bla', 'bia', 'waka', 'woka', 'wibba', 'lua', 'maya',
        'ba'
    ]),
    15: (['Chu', 'Dro', 'Al', 'Dem', 'Mor', 'Mur', 'Cro', 'Zul', 'Dra', 'The'],
         [
             'lu', 'kor', 'card', 'morius', 'enius', 'tus', 'demar', 'lus',
             'ruul', 'zad'
         ]),
    16: (['Xu', 'Dra', 'Al', 'Dem', 'Mor', 'Myr', 'Cra', 'Zul', 'Dri', 'Thu'],
         [
             'la', 'kira', 'cara', 'moria', 'ena', 'tana', 'diria', 'laza',
             'rah', 'zazah'
         ])
}

PIECES[18] = PIECES[2]
PIECES[43] = PIECES[2]
PIECES[83] = PIECES[2]
PIECES[45] = PIECES[3]
PIECES[84] = PIECES[3]


def generate(name_id, name_type=-1):
    a, b = PIECES.get(name_type, PIECES[-1])
    index1 = (13 * name_id + name_id / 7) % len(a)
    index2 = (name_id / 10 + 7 * name_id) % len(b)
    return a[index1] + b[index2]
