import re
laptops = open("laptops.txt",'r')
lines  = laptops.readlines()


price_REGEX = r"(?:[R$])(?:[0-9]{3}|[0-9]{2}|[0-9])(?:(?:,[0-9]{3})|[0-9]+)(?:(?:(?:\.[0-9]{2}))*)" 
processor_REGEX=r"[iI]ntel (?:(?:Core i[357][- ](?:[0-9]{4}(?:HQ|MQ|U))?)|(?:Pentium N[0-9]{4}))" 
brand_REGEX=r"(?:^by (\w+)$)"
newcount_REGEX=r"[0-9]+ new"
reviewcount_REGEX=r"[0-9]+ customer reviews"

#prices
for line in lines:
    x = re.findall(price_REGEX,line)
    for y in x:
        print(y)
print("________________")

#processors
for line in set(lines):
    x = re.findall(processor_REGEX,line)
    for y in x:
        print(y)
print("________________")

#brands
for line in set(lines):
    x = re.findall(brand_REGEX,line)
    for y in x:
        print(y)
    
print("________________")

#new
x=re.findall(newcount_REGEX,str(lines))
for y in x:
    print(re.sub(" new","",y))

print("________________")

#reviews
x=re.findall(reviewcount_REGEX,str(lines))
for y in x:
    print(re.sub(" customer reviews","",y))

