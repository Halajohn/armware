// ARMware - an ARM emulator
// Copyright (C) <2007>  Wei Hu <wei.hu.tw@gmail.com>
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef AddressSpace_hpp
#define AddressSpace_hpp

// Project include
//

#include "ARMware.hpp"

namespace ARMware
{
  // Forward declaration
  //
  
  class Core;
  class IntController;
  class GPIOControlBlock;
  class Serial_1;
  class Serial_2;
  class Serial_3;
  class RTC;
  class PPC;
  class Memory;
  class Egpio;
  class MemoryConf;
  class PowerManager;
  class ResetController;
  class RomFile;
  class LCDController;
  class OsTimer;
  
  typedef class AddressSpace AddressSpace;
  class AddressSpace
  {
  private:
    
    // Attribute
    
    Core              * const mp_core; // used for ENABLE_INST_RECALL
    IntController     *mp_int_controller;
    GPIOControlBlock  *mp_GPIO_control_block;
    Serial_1          *mpSerial_1;
    Serial_2          *mpSerial_2;
    Serial_3          *mpSerial_3;
    RTC               *mpRTC;
    PPC               *mpPPC;
    Memory            *mp_memory;
    Egpio             *mpEgpio;
    MemoryConf        *mp_memory_conf;
    PowerManager      *mpPowerManager;
    ResetController   *mpResetController;
    RomFile           *mpRomFile;
    LCDController     *mpLCDController;
    OsTimer           * const mpOsTimer;
    
  public:
    
    // Life cycle
    
    AddressSpace(Core *core, OsTimer *osTimer);
    
    // :NOTE: Wei 2003-Dec-23:
    //
    // If I don't declare the destructor,
    // the version implicitly generated by the compiler will be an 'inline public' one.
    // And this automated inline version will cause me have to include the definition of the 
    // class IntController, etc, rather than just forward declaration the class IntController, etc.
    ~AddressSpace();
    
    // Operation
    
    inline void
    RegisterIntController(IntController * const int_controller)
    { mp_int_controller = int_controller; }
    
    inline void
    RegisterGPIOControlBlock(GPIOControlBlock * const GPIO_control_block)
    { mp_GPIO_control_block = GPIO_control_block; }
    
    inline void
    RegisterSerial_1(Serial_1 * const serial_1)
    { mpSerial_1 = serial_1; }
    
    inline void
    RegisterSerial_2(Serial_2 * const serial_2)
    { mpSerial_2 = serial_2; }
    
    inline void
    RegisterSerial_3(Serial_3 * const serial_3)
    { mpSerial_3 = serial_3; }
    
    inline void
    RegisterRTC(RTC * const rtc)
    { mpRTC = rtc; }
    
    inline void
    RegisterPPC(PPC * const ppc)
    { mpPPC = ppc; }
    
    inline void
    RegisterEgpio(Egpio * const egpio)
    { mpEgpio = egpio; }
    
    inline void
    RegisterMemory(Memory * const memory)
    { mp_memory = memory; }
    
    inline void
    RegisterMemoryConf(MemoryConf * const memory_conf)
    { mp_memory_conf = memory_conf; }
    
    inline void
    RegisterPowerManager(PowerManager * const powerManager)
    { mpPowerManager = powerManager; }
    
    inline void
    RegisterResetController(ResetController * const resetController)
    { mpResetController = resetController; }
    
    inline void
    RegisterRomFile(RomFile * const romFile)
    { mpRomFile = romFile; }
    
    inline void
    RegisterLCDController(LCDController * const lcdController)
    { mpLCDController = lcdController; }
    
    template<typename T_return>
    T_return FASTCALL get_data(uint32_t const address, bool &exception_occur) const;
    
    template<typename T_store>
    void FASTCALL put_data(uint32_t const address, T_store const value);
  };
}

#endif
