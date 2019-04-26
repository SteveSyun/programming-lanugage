def declareVar(id, typeD, valD):
    print "Variable: "
    print "    Variable\t\ttype\t\tValue"
    for key in sorted(typeD):
        print "    ", key, "\t\t" , ', '.join(typeD[key]), "\t\t", ''.join(valD[key])
    
def declarela(label):
    print "Labels:"
    print "    Label\t\tstatement"
    for keys in sorted(label):
        print "    ", keys, "\t\t", ' '.join(label[keys])
    

