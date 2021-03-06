# cmsis_core
INCLUDES+= -I source/cmsis-core

# board
INCLUDES+=
CSOURCES+= source/board/stm32f103xb_bl.c

# target 相关文件，和编译器选择相关
INCLUDES+= -I source/target
CSOURCES+= source/target/target_board.c

# settings
INCLUDES+= -I source/daplink/settings
CSOURCES+= source/daplink/settings/settings.c \
           source/daplink/settings/settings_rom_stub.c

# daplink_bl
INCLUDES+= -I source/daplink \
           -I source/daplink/bootloader
# ASOURCES+= source/daplink/interface/SVC_Table.s
CSOURCES+= source/daplink/bootloader/main.c \
           source/daplink/bootloader/daplink.c \
           source/daplink/circ_buf.c \
           source/daplink/cortex_m.c \
           source/daplink/crc16.c \
           source/daplink/crc32.c \
           source/daplink/error.c \
           source/daplink/flash_hal.c \
           source/daplink/info.c \
           source/daplink/sdk_stub.c \
           source/daplink/util.c \
           source/daplink/validation.c

# drag-n-drap
INCLUDES+= -I source/daplink/drag-n-drop
CSOURCES+= source/daplink/drag-n-drop/file_stream.c \
           source/daplink/drag-n-drop/flash_decoder.c \
           source/daplink/drag-n-drop/flash_intf.c \
           source/daplink/drag-n-drop/flash_manager.c \
           source/daplink/drag-n-drop/iap_flash_intf.c \
           source/daplink/drag-n-drop/intelhex.c \
           source/daplink/drag-n-drop/vfs_manager.c \
           source/daplink/drag-n-drop/vfs_user.c \
           source/daplink/drag-n-drop/virtual_fs.c

# 启动文件

ASOURCES+= source/hic_hal/stm32/stm32f103xb/gcc/startup_stm32f103xb.s

# 外设驱动
INCLUDES+= -I source/hic_hal/stm32/stm32f103xb/STM32F1xx_HAL_Driver/Inc \
           -I source/hic_hal/stm32/stm32f103xb/STM32F1xx_HAL_Driver \
           -I source/hic_hal/stm32/stm32f103xb/cmsis \
           -I source/hic_hal/stm32/stm32f103xb \
           -I source/hic_hal

CSOURCES+= source/hic_hal/stm32/stm32f103xb/stm32f1xx_it.c \
           source/hic_hal/stm32/stm32f103xb/read_uid.c \
           source/hic_hal/stm32/stm32f103xb/flash.c \
           source/hic_hal/stm32/stm32f103xb/gpio.c \
           source/hic_hal/stm32/stm32f103xb/uart.c \
           source/hic_hal/stm32/stm32f103xb/usb_config.c \
           source/hic_hal/stm32/stm32f103xb/usbd_STM32F103.c \
           source/hic_hal/stm32/stm32f103xb/sdk.c \
           source/hic_hal/stm32/stm32f103xb/cmsis/system_stm32f1xx.c \
           source/hic_hal/stm32/stm32f103xb/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c \
           source/hic_hal/stm32/stm32f103xb/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c \
           source/hic_hal/stm32/stm32f103xb/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c \
           source/hic_hal/stm32/stm32f103xb/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.c \
           source/hic_hal/stm32/stm32f103xb/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.c \
           source/hic_hal/stm32/stm32f103xb/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c \
           source/hic_hal/stm32/stm32f103xb/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.c \
           source/hic_hal/stm32/stm32f103xb/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c \
           source/hic_hal/stm32/stm32f103xb/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.c \
           source/hic_hal/stm32/stm32f103xb/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.c \
           source/hic_hal/stm32/stm32f103xb/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.c \
           source/hic_hal/stm32/stm32f103xb/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_uart.c \
           source/hic_hal/stm32/stm32f103xb/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_usart.c

# rtos
# INCLUDES+= -I source/rtos
# CSOURCES+= source/rtos/cmsis_os2_port.c \
           source/rtos/cm3/HAL_CM3.c \
           source/rtos/rt_Event.c \
           source/rtos/rt_List.c \
           source/rtos/rt_Mailbox.c \
           source/rtos/rt_MemBox.c \
           source/rtos/rt_Mutex.c \
           source/rtos/rt_Robin.c \
           source/rtos/rt_Semaphore.c \
           source/rtos/rt_System.c \
           source/rtos/rt_Task.c \
           source/rtos/rt_Time.c \
           source/rtos/rt_Timer.c \
           source/rtos/RTX_Config.c

INCLUDES+= -I source/freertos/portable/GCC/ARM_CM3 \
           -I source/freertos/CMSIS_RTOS_V2 \
           -I source/freertos/include
CSOURCES+= source/freertos/CMSIS_RTOS_V2/cmsis_os2.c \
           source/freertos/croutine.c \
           source/freertos/event_groups.c \
           source/freertos/list.c \
           source/freertos/queue.c \
           source/freertos/stream_buffer.c \
           source/freertos/tasks.c \
           source/freertos/timers.c \
           source/freertos/portable/GCC/ARM_CM3/port.c \
           source/freertos/portable/MemMang/heap_4.c

# usb
INCLUDES+= -I source/usb
CSOURCES+= source/usb/usb_lib.c \
           source/usb/usbd_core.c \
           source/usb/msc/usbd_msc.c \
           source/usb/msc/usbd_core_msc.c

