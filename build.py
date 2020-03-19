import subprocess as sb

fp = open("cmds.txt", "r")

for st in fp:
    rtc = sb.call(st, shell=True)
    print("Compile stage:" + str(rtc))
    if not (rtc == 1 or rtc == 0):
        print("Errors found! In compile stange!")
        exit(-1)

rtc = sb.call("git add Test.c")
if not rtc == 0:
    print("Error adding files!")
    exit(-1)
rtc = sb.call("git commit -m \"Auto versioning\"")
if not rtc == 0:
    print("Error commiting files!")
    exit(-1)