_TEXT SEGMENT

; The PUBLIC modifier will make your function visible and callable outside

PUBLIC NtGlobalFlagx64


NtGlobalFlagx64 PROC
    xor rax, rax                ; clear eax
    mov rax, gs:[60h]           ; Reference start of the PEB
    mov rax, [rax + 0BCh]       ; PEB+0xBC points to NtGlobalFlag
    and rax, 70h                ; check three flags
    ret	                        ; return flag value into 'rax' which puts into 'found'
NtGlobalFlagx64 ENDP




_TEXT ENDS
 
END