//[label] [command] 
jmp start

start
	push label_test 
	push message
	push end
	jz 
	call hello_world
end
	push message
	over
	hlt
hello_world	
	push label_test 

test_loop
	load loop_cnt
	push 5
	push end_loop
	jz
	push message 
	prt 
	inc loop_cnt
	jmp test_loop
end_loop
	pop
	ret
label_test "This is test label string with number 12345"
message "Hello world!"
loop_cnt 0 
