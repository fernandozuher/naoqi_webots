#include "Low_Pass_Filter.hpp"

Low_Pass_Filter::Low_Pass_Filter(double time_interval, double rctime_constant)
    : m_current_filtered_value {0.0}, m_previous_filtered_value {0.0},
    m_current_raw_value {0.0}, m_size {0}
{
    m_alpha = time_interval / (rctime_constant + time_interval);
    m_one_minus_alpha = 1.0 - m_alpha;
}

static bool custom_isnan(double d)
{
    return d != d;
}

void Low_Pass_Filter::append_raw_value(double value)
{
    m_previous_filtered_value = m_current_filtered_value;
    m_current_raw_value = value;

    if (m_size > 0)
        m_current_filtered_value = m_alpha * m_current_raw_value +
                                m_one_minus_alpha * m_previous_filtered_value;
    else if (!custom_isnan(value)) // ! NaN + m_size == 0
        m_current_filtered_value = m_current_raw_value;
    else // NaN case
        m_current_filtered_value = 0.0;
    m_size++;
}

double Low_Pass_Filter::filtered_value() const
{
    return m_current_filtered_value;
}