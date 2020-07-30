// Description: Simulate an electronical low pass filter
// Source:      http://en.wikipedia.org/wiki/Lowpass_filter

#ifndef LOW_PASS_FILTER_HPP
#define LOW_PASS_FILTER_HPP

class Low_Pass_Filter
{
    private:
        double m_current_filtered_value, m_previous_filtered_value;
        double m_current_raw_value;
        double m_alpha, m_one_minus_alpha;
        int m_size;

    public:
        Low_Pass_Filter(double time_interval, double rctime_constant);

        void append_raw_value(double value);
        double filtered_value() const;
};

#endif
