#pragma once
#include <chrono>

class RunTime {
public:
    RunTime() : m_start(std::chrono::high_resolution_clock::now()), m_paused(false) {}

    void reset() {
        m_start = std::chrono::high_resolution_clock::now();
        m_paused = false;
    }

    void stop() {
        m_stop = std::chrono::high_resolution_clock::now();
        m_paused = true;
    }

    void resume() {
        if (m_paused) {
            auto paused_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_stop);
            m_start += paused_duration;
            m_paused = false;
        }
    }

    template <typename Duration = std::chrono::milliseconds>
    [[nodiscard]] long long elapsed() const {
        auto end = m_paused ? m_stop : std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<Duration>(end - m_start).count();
        return elapsed;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_stop;
    bool m_paused;
};
