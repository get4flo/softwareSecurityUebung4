
undefined8 01_main(void)

{
  int iVar1;
  long in_FS_OFFSET;
  char local_18 [8];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  02_setBuffers();
  puts(" Hello and welcome to my new experimental Fotispy app !");
  puts("Because of recent hacks, we only allow user management !");
  puts("====================================== =================");
  do {
    03_printOptions();
    04_readInput(local_18,2);
    iVar1 = atoi(local_18);
    switch(iVar1) {
    case 0:
      05_createUser();
      break;
    case 1:
      06_switchUser();
      break;
    case 2:
      07_editUser();
      break;
    case 3:
      08_showUser();
      break;
    case 4:
      09_deleteUser();
      break;
    default:
      if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
        return 0;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
  } while( true );
}


void 02_setBuffers(void)

{
  setvbuf(stdin,(char *)0x0,2,0);
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stderr,(char *)0x0,2,0);
  return;
}


void 03_printOptions(void)

{
  puts("[0] Create user");
  puts("[1] Switch user");
  puts("[2] Edit user");
  puts("[3] Show user");
  puts("[4] Delete user");
  printf("[~] Choice: ");
  return;
}


int 04_readInput(long param_1,long param_2)

{
  int iVar1;
  undefined1 local_d;
  undefined4 local_c;
  
  local_c = 0;
  do {
    if (param_2 <= local_c) break;
    iVar1 = _IO_getc(stdin);
    local_d = (char)iVar1;
    iVar1 = local_c + 1;
    *(char *)(local_c + param_1) = local_d;
    local_c = iVar1;
  } while (local_d != '\n');
  while (local_d != '\n') {
    iVar1 = _IO_getc(stdin);
    local_d = (char)iVar1;
  }
  if (local_c != param_2) {
    local_c = local_c + -1;
    *(undefined1 *)(param_1 + local_c) = 0;
  }
  return local_c;
}


void 05_createUser(void)

{
  uint uVar1;
  void *pvVar2;
  
  if (DAT_00602141 < 0x10) {
    uVar1 = (uint)DAT_00602141;
    pvVar2 = malloc(0x80);
    *(void **)(&DAT_006020c0 + (long)(int)uVar1 * 8) = pvV ar2;
    printf("[~] Enter a username: ");
    04_readInput(*(undefined8 *)(&DAT_006020c0 + (long)(i nt)(uint)DAT_00602141 * 8),0x40);
    printf("[~] Enter a password: ");
    04_readInput(*(long *)(&DAT_006020c0 + (long)(int)(uint )DAT_00602141 * 8) + 0x40,0x40);
    DAT_00602141 = DAT_00602141 + 1;
  }
  else {
    puts("[-] You created to many users already :(");
  }
  return;
}


void 06_switchUser(void)

{
  int iVar1;
  long in_FS_OFFSET;
  char local_18 [8];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf("[~] Please select an index [0-15]: ");
  04_readInput(local_18,3);
  iVar1 = atoi(local_18);
  if ((iVar1 < 0) || (0xf < iVar1)) {
    puts("[-] Please only enter valid indeces");
  }
  else {
    DAT_00602140 = (undefined1)iVar1;
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


void 07_editUser(void)

{
  if (*(long *)(&DAT_006020c0 + (long)(int)(uint)DAT_0060 2140 * 8) == 0) {
    puts("[-] No valid user selected");
  }
  else {
    printf("[~] Enter new name: ");
    04_readInput(*(undefined8 *)(&DAT_006020c0 + (long)(i nt)(uint)DAT_00602140 * 8),0x40);
    printf("[~] Enter new password: ");
    04_readInput(*(long *)(&DAT_006020c0 + (long)(int)(uint )DAT_00602140 * 8) + 0x40,0x50);
  }
  return;
}


void 08_showUser(void)

{
  if (*(long *)(&DAT_006020c0 + (long)(int)(uint)DAT_0060 2140 * 8) == 0) {
    puts("[-] No valid user selected");
  }
  else {
    printf("[~] Username: %s\n",*(undefined8 *)(&DAT_00602 0c0 + (long)(int)(uint)DAT_00602140 * 8));
    printf("[~] Password: %s\n",*(long *)(&DAT_006020c0 + ( long)(int)(uint)DAT_00602140 * 8) + 0x40)
    ;
  }
  return;
}


void 09_deleteUser(void)

{
  if (*(long *)(&DAT_006020c0 + (long)(int)(uint)DAT_0060 2140 * 8) == 0) {
    puts("[-] No valid user selected");
  }
  else {
    free(*(void **)(&DAT_006020c0 + (long)(int)(uint)DAT_0 0602140 * 8));
  }
  return;
}



