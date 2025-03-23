import sys
input = lambda:sys.stdin.readline().rstrip()
n,k = map(int,input().split())
pages = list(map(int,input().split()))
left,right=0,sum(pages)
mid = (left + right)//2
while left < right:
    flag = False
    student_index,assigned_pages=0,0
    for i in range(n):
        while student_index < k:
            if assigned_pages + pages[i] < mid:
                assigned_pages += pages[i]
                break
            else:
                student_index += 1
                assigned_pages = 0
        if student_index == k:
            flag = True
            break
    if flag: left = mid+1
    else: right = mid
    mid = (left+right)//2
print(mid-1)