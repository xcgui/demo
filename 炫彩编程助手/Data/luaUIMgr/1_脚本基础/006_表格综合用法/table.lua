

tb={
x=1,
y=2,
ff = function (a,b)
	return a+b;
end
}

print(tb.ff(tb.x,tb.y));



--进阶

tab ={};

tab.x = 3;
tab.y  = 2;
tab.sub = function (a,b)
	return a-b;
end

print( tab.sub(tab.x,tab.y) );

--增加一种写法

function tab.add(a,b)
	return a+b;
end

print(tab.add(tab.x,tab.y));

--高级进阶

ff={
x =10;
y =11;
};

function ff:Get()
	--只要用 ： 方法，里面就有了一个 self,就可以做更多的事了
	return self.x + self.y;
end


print("相加的值: ",ff:Get());