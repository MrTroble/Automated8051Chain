import subprocess as sb

fp = open("cmds.txt", "r")

for st in fp:
    rtc = sb.call(st, shell=True)
    print("Compile stage:" + str(rtc))
    if not (rtc == 1 or rtc == 0):
        print("Errors found! In compile stange!")
        exit(-1)