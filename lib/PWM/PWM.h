/**
 * @file PWM.h
 * @author Higor Grigorio dos Santos (higorgrigorio@gmail.com)
 * @brief declaration of PWM filter class
 * @version 0.1
 * @date 2022-07-14
 *
 * @copyright Copyright (c) 2022 Higor Grigorio dos Santos
 *
 */

#include <Arduino.h>

/**
 * @brief PWM filter class .
 *
 */
class PWM
{
public:
    /**
     * @brief Construct a new PWM object.
     *
     */
    PWM() = default;
    /**
     * @brief Read's the value of PWM in @c m_pin port.
     *
     * @return unsigned long.
     */
    unsigned long read() noexcept;
    /**
     * @brief calculate the off set value of PWM in @c m_pin port.
     *
     */
    void calculateOffSet(int = 100) noexcept;
    /**
     * @brief Attach a pointer in the handle.
     * This method is utility to bind reference with handle.
     *
     */
    void attach(unsigned long *) noexcept;
    /**
     * @brief Return true if the handle is attached, false otherwise.
     *
     * @return true.
     * @return false.
     */
    bool attached() noexcept;
    /**
     * @brief Exchange the handle with nullptr and return the pointer.
     *
     * @return unsigned long*.
     */
    unsigned long *detach() noexcept;
    /**
     * @brief Get's a pointer to the handle.
     *
     * @return unsigned long*.
     */
    unsigned long *put() noexcept;
    /**
     * @brief If attached, return the value on the handle.
     *
     * @return unsigned long
     */
    unsigned long value() noexcept;
    /**
     * @brief Get the Pin object
     *
     * @return byte
     */
    byte getPin() noexcept;
    /**
     * @brief Set the Pin object
     *
     */
    void setPin(byte) noexcept;
    /**
     * @brief Get the Offset object
     *
     * @return unsigned long
     */
    unsigned long getOffset() noexcept;
    /**
     * @brief Set the Offset object
     *
     * @param long
     */
    void setOffset(unsigned long) noexcept;

private:
    unsigned long *m_handle{nullptr};

    unsigned long m_value{0};
    byte m_pin;
    unsigned long m_off{0};
    bool m_useCalibrate{false};
};