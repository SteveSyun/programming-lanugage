#! /usr/bin/python
import sys
import re
from p5Dict import *
a=0
labelID={}
varTypeD={}
varValueD={}
tokenM={}
num=0
findCol= re.compile(r'^(\S*)\:')
findVar= re.compile(r'\VAR.*')
file =open(sys.argv[1], "r")
print "BEEP source code in ", sys.argv[1]
while True:
    inputLine = file.readline()
    a+=1
    matchCol = findCol.search(inputLine)
    matchVar = findVar.search(inputLine)
    if matchCol !=None:
        tokenT= re.split(':', matchCol.group().upper())
        labelID[tokenT[0]]= {str(a)}
        #print labelID
    if matchVar !=None:
        tokenK= re.split(' ',matchVar.group().upper())
        varTypeD[tokenK[2]]= {tokenK[1]}
        tokenM[num]={tokenK[2]}
        num+=1
        if len(tokenK)>3:
            varValueD[tokenK[2]]={tokenK[3].lower()}
        else: 
            varValueD[tokenK[2]]= " "
        #declareVar(labelID, tokenM[1], tokenM[2], tokenM[3])
    if inputLine =="":
        break
    inputLine = inputLine.rstrip('\n')
    print a,'.', inputLine
declareVar(tokenM, varTypeD, varValueD)
declarela(labelID)

file.close()
