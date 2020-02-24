import re
laptops = open("laptops.txt",'r')
lines  = laptops.readlines()
price_REGEX = r"(?:[R$])(?:[0-9]{3}|[0-9]{2}|[0-9])(?:(?:,[0-9]{3})|[0-9]+)(?:(?:(?:\.[0-9]{2}))*)" #works
processor_REGEX=r"[iI]ntel (?:(?:Core i[357][- ](?:[0-9]{4}(?:HQ|MQ|U))?)|(?:Pentium N[0-9]{4}))" #works
brand_REGEX=r'''(?:^by (?:\w)+$)'''#works
newcount_REGEX=r"[0-9]+ new"
reviewcount_REGEX=r"[0-9]+ customer reviews"#works

#prices
x = re.findall(price_REGEX,str(lines))
for y in x:
    print(y)
print()

#processors
x = re.findall(processor_REGEX,str(lines))
for y in x:
    print(y)
print()

#brands
b=[]
for line in lines:
    b+=re.findall(brand_REGEX,line)
for i in b:
    y=re.sub("by ","",i)
    print(y)
print()

#new
x=re.findall(newcount_REGEX,str(lines))
for y in x:
    print(re.sub(" new","",y))
print()

#reviews
x=re.findall(reviewcount_REGEX,str(lines))
for y in x:
    print(re.sub(" customer reviews","",y))
print()

