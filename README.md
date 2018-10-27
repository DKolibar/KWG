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
./kwg < INPUT_FILE_PATH
``` 

- On *Windows* download executable from EXE directory by clicking on "Open Raw" and run it through command line:
```console  
kwg INPUT_FILE_PATH
```
or drop INPUT FILE directly on executable file.

---

## HOW TO USE IT?
-To get valid results from generator you have to prepare VALID INPUT FILE. It is actually very easy proccess. You just copy the content of PROGRAM MAP but you only map part. You ignore first two lines with coordinates etc. I think with picture you will better understand it:![copy](https://i.imgur.com/8hsPq67.png) Format (.txt, .lol, ...) is not important. The file is passed to program as parameter. 
### It is important to dont have any new line after last word "AVE.": ![copy](https://i.imgur.com/oCgHpPi.png)

---

*Karel the Robot: [GIT](https://git.kpi.fei.tuke.sk/kpi/karel-the-robot) | Created by miroslav.binas@tuke.sk (c)2010, 2016*





