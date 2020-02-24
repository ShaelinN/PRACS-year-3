import re
import random
import time
#I AM SHAELIN NAIDOO 218003390. I AM THE ORIGINAL ATHOR OF THIS CODE. GITHUB REPOSITORY https://github.com/ShaelinN/PRACS-year-3 ,  FOLDER NLP_ASSIGNMENT.

def toMod():
    x = random.randrange(0, 100)
    return (x <= 98)
def timingAllowance(timer,instances):
    for i in range(0,5):
        time.sleep(timer)
        print(".",end = '')
    print()
    

def modifier(inputs):
    x = inputs.upper()
    # pronoun conversion
    # second person to place holder
    x = re.sub(r"\bYOU ARE\b", "2pyou_are", x)
    x = re.sub(r"\bYOU'RE\b", "2pyou_re", x)
    x = re.sub(r"\bYOU\b", "2pme", x)
    x = re.sub(r"\bYOUR\b", "2pmy", x)
    x = re.sub(r"\bYOURS\b", "2pmine", x)

    # first person to seond person
    x = re.sub(r"\bME\b", "YOU", x)
    x = re.sub(r"\bMY\b", "YOUR", x)
    x = re.sub(r"\bI\b", "YOU", x)
    x = re.sub(r"\bWE\b", "YOU", x)

    x = re.sub(r"'M", " ARE", x)
    x = re.sub(r"\bAM\b", "ARE", x)

    # place holder to first person
    x = re.sub(r"2pme", "ME", x)
    x = re.sub(r"2pmy\b", "MY", x)
    x = re.sub(r"2pmine", "MINE", x)
    x = re.sub(r"2pyou_are", "I AM", x)
    x = re.sub(r"2pyou_re", "I'M", x)
    
    #remove well from beginning sentences
    x = re.sub(r"\AWELL\b, ","",x)
    
    
    # keywords
    keywords = [
        r"(?:\bALL\b)",
        r"(?:\bALWAYS\b)",
        r"(?:\bDEPRESSED\b)|(?:\bSAD\b)",
        r"(?:\bUNHAPPY\b)",
        r"(?:\bYOU\b(?: (?:(?:\bJUST\b)|(?:\bREALLY\b)))* \bNEED\b) ([A-Z 0-9_]*)",

        r"\A(?:\bYOUR\b (?:(?:\bMOTHER\b)|(?:\bFATHER\b)) )([^.]+)",

        r"(?:\bYOUR\b (\bMOTHER\b|\bFATHER\b)\.)"

    ]

    substitutions = [
        ("IN WHAT WAY?", "HOW SO?"),
        ("CAN YOU THINK OF A SPECIFIC EXAMPLE?","CAN YOU GIVE ME AN EXAMPLE OF SOMETHING THAT MAKES YOU FEEL THIS WAY?"),
        ("I AM SORRY TO HEAR THAT YOU ARE {}.", "{} YOU SAY? I'M SORRY TO HEAR THAT."),
        ("DO YOU THINK THAT COMING HERE WILL HELP YOU NOT BE {}?",
         "DO YOU BELIEVE THAT COMING HERE CAN HELP OVERCOME BEING {}?"),
        ("WHAT WOULD IT MEAN IF YOU COULD GET {}?", "IF YOU WERE TO GET{},WHAT DO YOU THINK WILL HAPPEN?"),

        ("WHO ELSE {}?", "IS THERE ANYBODY ELSE WHO {}?"),

        ("TELL ME MORE ABOUT YOUR FAMILY.", "WHAT ELSE CAN YOU TELL ME ABOUT YOUR FAMILY?")
    ]

    for i in range(0, len(keywords)):
        pattern = keywords[i]
        # print("___________________________________________debugging: pattern is "+pattern)
        match = re.findall(pattern, x)
        # print("___________________________________________debugging: full match is "+ str(match))

        # random chance to use a substitution on this match
        useSubstitution = toMod()

        if match and useSubstitution:
            # pick a match group from groups in the full match
            match = random.choice(match)
            # print("___________________________________________debugging: match group is "+ match)
            # print("___________________________________________debugging: sub options are "+ str(substitutions[i]))
            x = random.choice(substitutions[i]).format(match)
            break
    return x


# main
inputs = 0
print("HI. I AM ELIZA")
timingAllowance(0.2,3)
print("I WILL BE YOUR THERAPIST TODAY.")
timingAllowance(0.2,3)
print("WHAT SEEMS TO BE THE PROBLEM?")

while input != ".":
    inputs = input()
    output = modifier(inputs)
    timingAllowance(0.35,4)
    if(input == "."):
        print("!")
        break
    print(output)
