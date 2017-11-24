input_from_user = input("")
input_from_user=input_from_user.lower()
input_from_user=input_from_user.replace('.','')
print(input_from_user)
output = input_from_user.split(' ');
length=len(output)
print(length)
count=0;
i=1;
flag=0;
while 1:
    if(count==length):
        break;break;
    else:
        #print(count)
        for word in output:
            if(len(word)==i):
                if(flag==0):
                    count+=1
                    flag=1
                    wrd=str(word)
                    print(wrd.title(),end='')
                else:
                    count+=1
                    print(' ',end='')
                    print(word,end='')
        else:
            if(count==length):
                break;
        i+=1
print('.',end='')

