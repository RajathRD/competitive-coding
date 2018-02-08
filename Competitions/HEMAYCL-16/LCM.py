def gcd (a,b):
  return a if b==0 else gcd(b,a%b)

def lcm (a,b):
  return a * (b / gcd(a,b))

def magic1(N):
  result = 1
  for i in range(2,N+1):
      result = lcm(result,i)
  return result

def magic2(M,N):
  result = 1
  for i in range(M,N+1):
      result = lcm(result,i)
  return result
for N in xrange(600,900):
    #N = int(raw_input())
    LCM = magic1(N)

    for i in xrange(N//2, N+1):
        check = magic2(i,N)
        #print i,"-",N," LCM: ",check;
        if check != LCM:
            break
    print N,": ",i-1," ",N//2
