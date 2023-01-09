#pragma once

template <typename T = int>
class ChangeTracker {
public:
    ChangeTracker()
        : received_initial_(false)
        , has_changed_flag_(false)
    {
    }

    void input(T value)
    {
        if (!received_initial_)
            received_initial_ = true;
        else if (is_trigger(value))
            has_changed_flag_ = true;
        prev_value_ = value;
    }

    bool output(bool reset = true)
    {
        bool result = has_changed_flag_;
        if (reset) {
            has_changed_flag_ = false;
        }
        return result;
    }

    void trigger()
    {
        has_changed_flag_ = true;
    }

protected:
    T prev_value_;

private:
    bool received_initial_;
    bool has_changed_flag_;

    virtual bool is_trigger(T value)
    {
        return prev_value_ != value;
    }
};

template <typename T = int>
class PositiveFlankTracker : public ChangeTracker<T> {
private:
    bool is_trigger(T val) override
    {
        return (val > this->prev_value_);
    }
};

template <typename T = int>
class NegativeFlankTracker : public ChangeTracker<T> {
private:
    bool is_trigger(T val) override
    {
        return (val < this->prev_value_);
    }
};
