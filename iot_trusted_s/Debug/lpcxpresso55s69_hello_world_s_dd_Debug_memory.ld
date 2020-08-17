/*
 * GENERATED FILE - DO NOT EDIT
 * Copyright (c) 2008-2013 Code Red Technologies Ltd,
 * Copyright 2015, 2018-2019 NXP
 * (c) NXP Semiconductors 2013-2019
 * Generated linker script file for LPC55S69
 * Created from memory.ldt by FMCreateLinkMemory
 * Using Freemarker v2.3.23
 * MCUXpresso IDE v11.0.0 [Build 2516] [2019-06-05] on 2019-11-17 11:09:30
 */

MEMORY
{
  /* Define each memory region */
  PROGRAM_FLASH (rx) : ORIGIN = 0x10000000, LENGTH = 0x52f00 /* 339712 bytes (alias Flash) */  
  SG_veneer_table (rx) : ORIGIN = 0x10052f00, LENGTH = 0x200 /* 512 bytes (alias Flash2) */  
  Ram0 (rwx) : ORIGIN = 0x30000000, LENGTH = 0x1fff0 /* 131056 bytes (alias RAM) */  
  Ram_1 (rwx) : ORIGIN = 0x3001fff0, LENGTH = 0x4000 /* 16K bytes (alias RAM2) */  
}

  /* Define a symbol for the top of each memory region */
  __base_PROGRAM_FLASH = 0x10000000  ; /* PROGRAM_FLASH */  
  __base_Flash = 0x10000000 ; /* Flash */  
  __top_PROGRAM_FLASH = 0x10000000 + 0x52f00 ; /* 339712 bytes */  
  __top_Flash = 0x10000000 + 0x52f00 ; /* 339712 bytes */  
  __base_SG_veneer_table = 0x10052f00  ; /* SG_veneer_table */  
  __base_Flash2 = 0x10052f00 ; /* Flash2 */  
  __top_SG_veneer_table = 0x10052f00 + 0x200 ; /* 512 bytes */  
  __top_Flash2 = 0x10052f00 + 0x200 ; /* 512 bytes */  
  __base_Ram0 = 0x30000000  ; /* Ram0 */  
  __base_RAM = 0x30000000 ; /* RAM */  
  __top_Ram0 = 0x30000000 + 0x1fff0 ; /* 131056 bytes */  
  __top_RAM = 0x30000000 + 0x1fff0 ; /* 131056 bytes */  
  __base_Ram_1 = 0x3001fff0  ; /* Ram_1 */  
  __base_RAM2 = 0x3001fff0 ; /* RAM2 */  
  __top_Ram_1 = 0x3001fff0 + 0x4000 ; /* 16K bytes */  
  __top_RAM2 = 0x3001fff0 + 0x4000 ; /* 16K bytes */  
