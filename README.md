# Vector
## 1. Vektorių funkcijų palyginimas (funkcijos.cpp)
#### 1)PUSH_BACK <br>
<img width="707" alt="Screenshot 2023-05-20 at 18 50 59" src="https://github.com/bei-m/Vector/assets/116886672/047c5dda-cba1-4b97-8d66-e4977327541e">

#### 2)POP_BACK
<img width="709" alt="Screenshot 2023-05-20 at 18 51 08" src="https://github.com/bei-m/Vector/assets/116886672/1acd8f22-68b3-48b8-bd0a-b5bac650df25">

#### 3)RESERVE
<img width="702" alt="Screenshot 2023-05-20 at 18 51 15" src="https://github.com/bei-m/Vector/assets/116886672/72c626e0-b428-42e3-bfe3-1ed6f36df00c">

#### 4)SHRINK_TO_FIT
<img width="702" alt="Screenshot 2023-05-20 at 18 51 23" src="https://github.com/bei-m/Vector/assets/116886672/3d48fbb7-1d74-456a-9a70-f453b976b16a">

#### 5)FRONT
<img width="324" alt="Screenshot 2023-05-20 at 18 51 35" src="https://github.com/bei-m/Vector/assets/116886672/828dc9ed-a3e8-40f0-81bd-4b8e41ace0a5">

## 2. Vektorių spartos analizė (kiti_testai.cpp)
|           | std::vector   | Vector(custom) |
|-----------|---------------|----------------|
| 10000     | 6.8693e-05 s  | 9.3056e-05 s   |
| 100000    | 0.000631235 s | 0.00112044 s   |
| 1000000   | 0.00230971 s  | 0.0049707 s    |
| 10000000  | 0.0333558 s   | 0.0677074 s    |
| 100000000 | 0.549685 s    | 0.511035 s     |

## 3. Atminties perskirstymas užpildant 100000000 elementų
|                | perskirstymų kiekis kartais: |
|:--------------:|:----------------------------:|
|   std::vector  |              28              |
| Vector(custom) |              28              |

## 4. Spartos analizė naudojant programoje
Testavimo parametrai: 100 000 įrašų failas, 1 testavimo startegija. <br>
|                                                              | std::vector | Vector(custom) |
|:------------------------------------------------------------:|:-----------:|:--------------:|
| Failo nuskaitymo ir galutinių pažymių <br>skaičiavimo laikas |  0.233176 s |   0.231478 s   |
|           Failo įrašų dalijimo į dvi grupes laikas           |  0.010467 s |   0.0164917 s  |
|         Failo įrašų rūšiavimo abėcėlės tvarka laikas         | 0.0731692 s |   0.136841 s   |
|   Grupių 'protingieji' ir 'vargsai' įrašymo į failą laikas   |  0.46312 s  |   0.443742 s   |
|                Visos programos veikimo laikas                |  0.779976 s |   0.837404 s   |







