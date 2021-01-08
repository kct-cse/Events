n = int(input())

output = []
for i in range(0, n) : 
    output.insert(i, (n-i) * "* " + " " * (4*i) + (n-i) * " *"); 
    
for i in range(0, n) : 
    print(output[i])
    
for i in range(0, n) : 
    print(output[n-i-1]); 
