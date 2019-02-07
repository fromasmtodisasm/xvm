//[label] [command] 
jmp start

start
	push message
	push end
	jz 
	call hello_world
end
	over
	hlt
hello_world	
	push message
	prt 
	ret
message "Hello world!"
