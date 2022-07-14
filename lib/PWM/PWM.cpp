/**
 * @file PWM.cpp
 * @author Higor Grigorio dos Santos (higorgrigorio@gmail.com)
 * @brief implementation of PWM filter class
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022 Higor Grigorio dos Santos
 *
 */

#include <PWM.h>

unsigned long PWM::read() noexcept
{
    unsigned long reading = pulseIn(m_pin, HIGH);

    if (m_useCalibrate)
    {
        if (m_handle)
        {
            if (reading > (*m_handle + m_off) || reading < (*m_handle - m_off))
            {
                *m_handle = reading;
            }
        }
        else
        {
            if (reading > (m_value + m_off) || reading < (m_value - m_off))
            {
                m_value = reading;
            }
        }
    }
    else
    {
        if (m_handle)
        {
            *m_handle = reading;
        }
        else
        {
            m_value = reading;
        }
    }

    return value();
}

void PWM::calculateOffSet(int sampleSize) noexcept
{
    if (sampleSize > 500)
    {
        return;
    }

    int sum = 0, average = 0, summation = 0;
    int *sample = new int[sampleSize];

    for (int i = 0; i < sampleSize; i++)
    {
        sample[i] = read();
        sum += sample[i];
    }

    average = abs(sum / sampleSize);

    for (int i = 0; i < sampleSize; i++)
    {
        summation = pow((sample[i] - average), 2);
    }

    delete sample;

    // sum .5 to round up.
    m_off = (sqrt(summation / (sampleSize)) * .65) + 0.5;
    m_useCalibrate = true;
}

void PWM::attach(unsigned long *pointer) noexcept
{
    m_handle = pointer;
}

bool PWM::attached() noexcept
{
    return m_handle != nullptr;
}

unsigned long *PWM::detach() noexcept
{
    auto temp = m_handle;
    m_handle = nullptr;
    return temp;
}

unsigned long *PWM::put() noexcept
{
    return m_handle;
}

unsigned long PWM::value() noexcept
{
    return m_handle ? *m_handle : m_value;
}

void PWM::setPin(byte pin) noexcept
{
    m_pin = pin;
}

byte PWM::getPin() noexcept
{
    return m_pin;
}

unsigned long PWM::getOffset() noexcept
{
    return m_off;
}

void PWM::setOffset(unsigned long value) noexcept
{
    m_off = value;
    m_useCalibrate = true;
}