import re
import random
import time

def toMod():
    x = random.randrange(0,10)
    return (x <=8) or True

def modifier(inputs):
    x = inputs.upper()
    #pronoun conversion
    x = re.sub(r"\bME\b","YOU",x) 
    x = re.sub(r"\bMY\b","YOUR",x) 
    x = re.sub(r"\bI\b","YOU",x) 
    x = re.sub(r"\bWE\b","YOU",x) 

    x = re.sub(r"'M"," ARE",x) 
    x = re.sub(r"\bAM\b","ARE",x) 


    #keywords
    keywords = [
        #for these keywords the entire keyword is what will go into the output
        r"(?:\bALL\b)",
        r"(?:\bALWAYS\b)",
        r"(?:\bDEPRESSED\b)|(?:\bSAD\b)",
        r"(?:\bUNHAPPY\b)",
        r"(?:\bYOU\b(?: \bJUST\b)* \bNEED\b) ([A-Z 0-9_]*)",

        r"\A(?:\bYOUR\b (?:(?:\bMOTHER\b)|(?:\bFATHER\b)) )([^.]+)",

        r"(?:\bYOUR\b (\bMOTHER\b|\bFATHER\b)\.)"

    ]
    
    substitutions = [
        ("IN WHAT WAY?","HOW SO?"),
        ("CAN YOU THINK OF A SPECIFIC EXAMPLE?","CAN YOU GIVE ME AN EXAMPLE OF SOMETHING THAT MAKES YOU FEEL THIS WAY?"),
        ("I AM SORRY TO HEAR THAT YOU ARE {}.","{} YOU SAY? I'M SORRY TO HEAR THAT."),
        ("DO YOU THINK THAT COMING HERE WILL HELP YOU NOT BE {}?","DO YOU BELIEVE THAT COMING HERE CAN HELP OVERCOME BEING {}?"),
        ("WHAT WOULD IT MEAN IF YOU COULD GET {}?","IF YOU WER TO GET{},WHAT DO YOU THINK WILL HAPPEN?"),

        ("WHO ELSE {}?","IS THERE ANYBODY ELSE WHO {}?"),

        ("TELL ME MORE ABOUT YOUR FAMILY.","WHAT ELSE CAN YOU TELL ME ABOUT YOUR FAMILY?")
    ]

    for i in range(0, len(keywords)):
        pattern = keywords[i]
        #print("___________________________________________debugging: pattern is "+pattern)
        match = re.findall(pattern,x)
        #print("___________________________________________debugging: full match is "+ str(match))

        #random chance to use a substitution on this match
        useSubstitution = toMod()

        if match and useSubstitution:
            #pick a match group from groups in the full match
            match = random.choice(match)
            #print("___________________________________________debugging: match group is "+ match)
            #print("___________________________________________debugging: sub options are "+ str(substitutions[i]))
            x = random.choice(substitutions[i]).format(match)
            break
    return x 





#main   
inputs=0
while(inputs != -1):
    inputs = input()
    output = modifier(inputs)
    time.sleep(1)
    print(output)
