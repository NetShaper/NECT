#pH34r-pH
import string
import random
import colorama
from colorama import init, Fore, Back, Style
init()

user = ["","","","",""]
read = ["","","","",""]

comm = 0
item = 0
arg0 = 1
arg1 = 2
optn = 3

run = 1
skip = 1
line = Fore.RED+Style.BRIGHT+"***********************************************"+Fore.RESET+Style.NORMAL
print(line+"\nLoading interface...")
name = input("Enter user name: ")
print("Loading user profile...\nWelcome back "+name+"!")

while(run):
    #holy shit I forgot how much easier python is
    command = input("C:\\user\\"+name+"\\mem: ")
    read = [x for x in command.split(':')]
    while '' in read:
        read.remove('')
    #these four lines do 25+ lines of C work and then some
    if read[comm] == "exit":
        skip = 0
        print("Exiting terminal.\n"+line)
        run = 0
    if read[comm] == "help":
        skip = 0
        print(Fore.GREEN+Style.BRIGHT+"Need some help?\n\nBasic command format:"+Style.NORMAL+"\n  Command::Argument1:Argument2::END")
        print("  Command::Argument1:Argument2:Option::END")
        print(Style.BRIGHT+"Standalone commands:"+Style.NORMAL+"\n  help - displays this!")
        print("  exit - Exits terminal\n"+Style.BRIGHT+"Command Arguments:"+Style.NORMAL+"\n  LOAD: - Select Item\n  SET: - Set target of Item")
        print("  FIRE: - Fire or execute Item\n"+Style.BRIGHT+"Argument one and two options:"+Style.NORMAL+"\n  LOAD - weapon:ammunition")
        print("  SET - target:source\n  FIRE - weapon:target\n"+Style.BRIGHT+"Option Arguments:"+Style.NORMAL+"\n  END - Do nothing")
        print("  RELOAD - Reloads last fired weapon"+Fore.RESET)
    if read[comm] == "LOAD":
        skip = 0
        if read[arg0] == user[item]:
            print(Fore.GREEN+"> "+read[arg0]+" already loaded!")
        elif read[arg0] != user[item]:
            if random.randint(0, 1000) > 975:#gives a 2.5% chance of failure to load
                print(Fore.RED+Style.BRIGHT+"> Error! "+read[arg0]+" failed to load!"+Style.NORMAL)
            else:
                print(Fore.GREEN+"> "+read[arg0]+".initialize successful!")
                user[item] = read[arg0]
            
        if (read[arg1] == user[arg1]) and (read[arg0] == user[item]):
            print("> "+read[arg0]+"."+read[arg1]+" already loaded!"+Fore.RESET)
        elif read[arg1] != user[arg1]:
            if random.randint(0, 1000) > 975:#gives a 2.5% chance of failure to load
                print(Fore.RED+Style.BRIGHT+"> Error! "+read[arg0]+"."+read[arg1]+".initialize failed to execute!"+Fore.RESET+Style.NORMAL)
            else:
                print("> "+read[arg0]+"."+read[arg1]+".initialize successful!"+Fore.RESET)
                user[arg1] = read[arg1]
    if read[comm] == "SET":
        skip = 0
        if read[arg0] == user[arg0]:
            print(Fore.GREEN+"> "+read[arg0]+" already selected!")
        elif read[arg0] != user[arg0]:
            if random.randint(0, 1000) > 975:#gives a 2.5% chance of failure to load
                print(Fore.RED+Style.BRIGHT+"> Error! "+read[arg0]+" failed to load!"+Style.NORMAL)
            else:
                print(Fore.GREEN+"> "+read[arg0]+".initialize successful!")
                user[arg0] = read[arg0]
            
        if (read[arg1] == user[arg1]) and (read[arg0] == user[arg0]):
            print("> Input from "+read[arg0]+"."+read[arg1]+" already loaded!"+Fore.RESET)
        elif read[arg1] != user[arg1]:
            if random.randint(0, 1000) > 975:#gives a 2.5% chance of failure to load
                print(Fore.RED+Style.BRIGHT+"> Error! "+read[arg0]+"."+read[arg1]+".initialize failed to execute!"+Fore.RESET+Style.NORMAL)
            else:
                print("> Input from "+read[arg0]+"."+read[arg1]+".initialize successfully retrieved!"+Fore.RESET)
    if read[comm] == "FIRE":
        skip = 0
        fired = 0;
        if read[arg0].lower() != "target":
            print(Fore.GREEN+"> Error! arg0 must be \"target\"!")
        elif read[arg0].lower() == "target":
            if random.randint(0, 1000) > 975:#gives a 2.5% chance of failure to fire
                print(Fore.RED+Style.BRIGHT+"> Error! "+read[arg0]+".data failed to load!"+Style.NORMAL)
            else:
                print(Fore.GREEN+"> "+read[arg0]+" selected!")
                fired = 1;
            
        if (read[arg1] == user[item]):
            if random.randint(0, 1000) > 975:#gives a 2.5% chance of failure to fire
                print(Fore.RED+Style.BRIGHT+"> Error! "+read[arg1]+".fire failed to execute!"+Fore.RESET+Style.NORMAL)
            else:
                print("> "+user[item]+".state: Fired successfully!"+Fore.RESET)
                if read[optn].lower() == "reload":
                    print(Fore.GREEN+"> "+user[item]+".reload.LastUsed: successful!"+Fore.RESET)
        elif read[arg1] != user[item]:
            print(Fore.RED+Style.BRIGHT+"> Error! "+read[arg1]+".fire failed to execute: "+user[item]+" currently loaded!"+Fore.RESET+Style.NORMAL)
    if skip == 1:
        print(Fore.RED+Style.BRIGHT+"> '"+read[comm]+"' is not recognized as an internal or external command,\noperable program or batch file."+Style.NORMAL+Fore.RESET)
                
