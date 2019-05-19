
tb={x=1,y=2};

--复习上个例子的用法
for k,v in pairs(tb) do
	print(k,v);
end


--进阶

print("进阶用法： ",tb['x'],tb['y']);


--二次进阶


print("二次进阶：",tb.x,tb.y);