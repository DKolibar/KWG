# KWG - KAREL WORLD GENERATOR

I created this program as coding "exercise".
Program generates Karel world from text structure inside INPUT file.

---

- On *UNIX* compile with 
```console 
gcc src/main.c -std=c11 -Wall -Werror -o kwg 
``` 
and run it:
```console 
./kwg INPUT_FILE_PATH
``` 
---

- On *Windows* download executable from [EXE directory](https://github.com/DKolibar/KWG/tree/master/EXE) by clicking on "Open Raw" and run it through command line:
```console  
kwg INPUT_FILE_PATH
```
or drag n drop INPUT FILE directly on executable file.

---

## HOW TO USE IT?
- To get valid results from generator you have to prepare VALID INPUT FILE. It is actually very easy proccess. You just copy the content of PROGRAM MAP but you only map part. You ignore first two lines with coordinates etc. I think with picture you will better understand it:![copy](https://i.imgur.com/8hsPq67.png)

- Format (.txt, .lol, ...) is not important. The file is passed to program as parameter.

- After launch, program will ask you, for STARTING AMOUNT of beepers in Karel bag. Enter amount and press Enter!

- After sucessfull execution program will generate <INPUT_FILE>.kw in directory of executable.

- #### If there is map with over 99 amount of beepers PROGRAM WONT WORK!

---

#### PARAMETERS
```console
Usage: KWG path_to_map_text_file [-D]

Options:
   
   -D      Show debug info
```

---

*By Daniel Kolibár | dkolibar@gmail.com*

*Karel the Robot: [GIT](https://git.kpi.fei.tuke.sk/kpi/karel-the-robot) | Created by miroslav.binas@tuke.sk (c)2010, 2016*
