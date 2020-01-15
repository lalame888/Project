INCLUDE Irvine32.inc
.data
temp DWORD 0
temp2 DWORD 0
i DWORD 10

.code
main PROC
mov al,'i'
call WriteChar
mov al,'='
call WriteChar
mov al,' '
call WriteChar
push i
pop eax
mov temp , eax
call WriteDec
mov al,' '
call WriteChar
call Crlf
call Crlf
call WaitMsg
main ENDP
END main
