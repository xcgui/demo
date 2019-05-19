
local a = 1;
local b = 2;

if a>b then
	print("a > b");
else	
	print("a < b");
end


--进阶用法
local c,d=2,1;
if c>d then
	print("c > d");
else	
	print("c < d");
end


--扩展阅读
maxRepetCount = 10;  --最大执行次数
stepSize = 1;        --每次i要加的值
for i=1,maxRepetCount,stepSize do
	print(i);
end


maxCount = 10;
start = 1;
repeat
	print(start);
	start=start+1;	
until start > maxCount


while start > 0 do
	print(start);
	start=start-1;
end