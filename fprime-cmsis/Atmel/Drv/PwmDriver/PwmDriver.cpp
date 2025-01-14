// ======================================================================
// \title  PwmDriver.cpp
// \author ethan
// \brief  cpp file for PwmDriver component implementation class
// ======================================================================


#include <Atmel/Drv/PwmDriver/PwmDriver.hpp>
#include <FpConfig.hpp>
#include <FprimeAtmel.hpp>

namespace Atmel {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  PwmDriver ::
    PwmDriver(
        const char *const compName
    ) : PwmDriverComponentBase(compName), m_pin(-1)
  {

  }

  PwmDriver ::
    ~PwmDriver()
  {

  }

  void PwmDriver::open(NATIVE_INT_TYPE gpio)
  {
    this->m_pin = gpio;
    pinMode(this->m_pin, Atmel::DEF_OUTPUT);
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  Fw::Success PwmDriver ::
    setDutyCycle_handler(
        const NATIVE_INT_TYPE portNum,
        U8 dutyCycle
    )
  {
    if (dutyCycle > 100) {
        dutyCycle = 100;
    }

    analogWrite(this->m_pin, 255 * (static_cast<F32>(dutyCycle) / 100));
    return Fw::Success::SUCCESS;
  }

} // end namespace Atmel
