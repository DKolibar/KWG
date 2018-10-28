# KWG - KAREL WORLD GENERATOR

I created this program as coding "exercise".
Program generates Karel world from text structure inside of *input file*.

![badge](https://img.shields.io/badge/-TUKE-red.svg)
![badge](https://img.shields.io/badge/testen_on:-UNIX-orange.svg)
![badge](https://img.shields.io/badge/testen_on:-Windows-blue.svg)

---

[![badge](https://img.shields.io/badge/latest%20release:-CLICK_HERE!-brightgreen.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/DKolibar/KWG/releases)
[![GitHub All Releases](https://img.shields.io/github/downloads/DKolibar/KWG/total.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/DKolibar/KWG/releases)

---

## TUTORIAL:

### - Running:

On *UNIX* run with:
```console
./kwg path_to_map_text_file beepers_amount_at_start
```

On *Windows* run **THROUGH COMMAND LINE** with:
```console
KWG path_to_map_text_file beepers_amount_at_start
```

### - Preparing map for generator:
 
 - To get valid result from generator you have to prepare **VALID input file**. But don't worry it is actually very easy process.
  
 - You just have to copy the **map from Karel output** to your favourite editor (Notepad, Vim) and **ignore first two lines** with coordinates etc.
 
 Example with Vim:![copy](https://i.imgur.com/pZuaLMc.png)
 
 *Tip for Vim*: When pasting to Vim you should toggle `:set paste!` first. Otherwise Vim will do indentation to the pasted text.

 - Type of file (.txt, ...) is **not important**. The file is passed to program as parameter.

 - After sucessfull execution program will prints out **"Done."** and generate **<input_file>.kw** in directory.

 - ##### Note: If there is map with amount of placed beepers over 99, generator won't work! Yet...

---

#### Flags:
```console   
   -D      Show debug info
```

---

*By Daniel Kolibár | dkolibar@gmail.com*

*Karel the Robot: [GIT](https://git.kpi.fei.tuke.sk/kpi/karel-the-robot) | Created by miroslav.binas@tuke.sk (c)2010, 2016*
