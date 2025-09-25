#include <cmath>
#include <algorithm>

using Float64 = double;

class Ease {
public:
        /**
     * @brief Easing function accelerating from zero velocity.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Quadratic ease-in value.
     */
    static constexpr Float64 inQuad(Float64 t) noexcept {
        return t * t;
    }

    /**
     * @brief Easing function decelerating to zero velocity.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Quadratic ease-out value.
     */
    static constexpr Float64 outQuad(Float64 t) noexcept {
        return -t * (t - 2.0);
    }

    /**
     * @brief Easing function accelerating until halfway, then decelerating.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Quadratic ease-in-out value.
     */
    static constexpr Float64 inOutQuad(Float64 t) noexcept {
        t *= 2.0;
        if (t < 1.0) return 0.5 * t * t;
        t -= 1.0;
        return -0.5 * (t * (t - 2.0) - 1.0);
    }

    /**
     * @brief Cubic easing in – accelerating from zero velocity.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Cubic ease-in value.
     */
    static constexpr Float64 inCubic(Float64 t) noexcept {
        return t * t * t;
    }

    /**
     * @brief Cubic easing out – decelerating to zero velocity.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Cubic ease-out value.
     */
    static constexpr Float64 outCubic(Float64 t) noexcept {
        t -= 1.0;
        return t * t * t + 1.0;
    }

    /**
     * @brief Cubic easing in/out – acceleration until halfway, then deceleration.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Cubic ease-in-out value.
     */
    static constexpr Float64 inOutCubic(Float64 t) noexcept {
        t *= 2.0;
        if (t < 1.0) return 0.5 * t * t * t;
        t -= 2.0;
        return 0.5 * (t * t * t + 2.0);
    }

    /**
     * @brief Quartic easing in – accelerating from zero velocity.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Quartic ease-in value.
     */
    static constexpr Float64 inQuart(Float64 t) noexcept {
        return t * t * t * t;
    }

    /**
     * @brief Quartic easing out – decelerating to zero velocity.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Quartic ease-out value.
     */
    static constexpr Float64 outQuart(Float64 t) noexcept {
        t -= 1.0;
        return -(t * t * t * t - 1.0);
    }

    /**
     * @brief Quartic easing in/out – acceleration until halfway, then deceleration.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Quartic ease-in-out value.
     */
    static constexpr Float64 inOutQuart(Float64 t) noexcept {
        t *= 2.0;
        if (t < 1.0) return 0.5 * t * t * t * t;
        t -= 2.0;
        return -0.5 * (t * t * t * t - 2.0);
    }

    /**
     * @brief Quintic easing in – accelerating from zero velocity.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Quintic ease-in value.
     */
    static constexpr Float64 inQuint(Float64 t) noexcept {
        return t * t * t * t * t;
    }

    /**
     * @brief Quintic easing out – decelerating to zero velocity.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Quintic ease-out value.
     */
    static constexpr Float64 outQuint(Float64 t) noexcept {
        t -= 1.0;
        return t * t * t * t * t + 1.0;
    }

    /**
     * @brief Quintic easing in/out – acceleration until halfway, then deceleration.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Quintic ease-in-out value.
     */
    static constexpr Float64 inOutQuint(Float64 t) noexcept {
        t *= 2.0;
        if (t < 1.0) return 0.5 * t * t * t * t * t;
        t -= 2.0;
        return 0.5 * (t * t * t * t * t + 2.0);
    }

    /**
     * @brief Sine easing in – accelerating from zero velocity.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Sine ease-in value.
     */
    static inline Float64 inSine(Float64 t) noexcept {
        return 1.0 - std::cos(t * M_PI / 2.0);
    }

    /**
     * @brief Sine easing out – decelerating to zero velocity.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Sine ease-out value.
     */
    static inline Float64 outSine(Float64 t) noexcept {
        return std::sin(t * M_PI / 2.0);
    }

    /**
     * @brief Sine easing in/out – acceleration until halfway, then deceleration.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Sine ease-in-out value.
     */
    static inline Float64 inOutSine(Float64 t) noexcept {
        return -0.5 * (std::cos(M_PI * t) - 1.0);
    }

    /**
     * @brief Exponential easing in – accelerating from zero velocity.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Exponential ease-in value.
     */
    static inline Float64 inExpo(Float64 t) noexcept {
        if (t <= 0.0) return 0.0;
        return std::pow(2.0, 10.0 * (t - 1.0));
    }

    /**
     * @brief Exponential easing out – decelerating to zero velocity.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Exponential ease-out value.
     */
    static inline Float64 outExpo(Float64 t) noexcept {
        if (t >= 1.0) return 1.0;
        return 1.0 - std::pow(2.0, -10.0 * t);
    }

    /**
     * @brief Exponential easing in/out – acceleration until halfway, then deceleration.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Exponential ease-in-out value.
     */
    static inline Float64 inOutExpo(Float64 t) noexcept {
        if (t <= 0.0) return 0.0;
        if (t >= 1.0) return 1.0;
        t *= 2.0;
        if (t < 1.0) return 0.5 * std::pow(2.0, 10.0 * (t - 1.0));
        return 0.5 * (2.0 - std::pow(2.0, -10.0 * (t - 1.0)));
    }

    /**
     * @brief Circular easing in – accelerating from zero velocity.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Circular ease-in value.
     */
    static constexpr Float64 inCirc(Float64 t) noexcept {
        return -(std::sqrt(1.0 - t * t) - 1.0);
    }

    /**
     * @brief Circular easing out – decelerating to zero velocity.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Circular ease-out value.
     */
    static constexpr Float64 outCirc(Float64 t) noexcept {
        t -= 1.0;
        return std::sqrt(1.0 - t * t);
    }

    /**
     * @brief Circular easing in/out – acceleration until halfway, then deceleration.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Circular ease-in-out value.
     */
    static constexpr Float64 inOutCirc(Float64 t) noexcept {
        t *= 2.0;
        if (t < 1.0) return -0.5 * (std::sqrt(1.0 - t * t) - 1.0);
        t -= 2.0;
        return 0.5 * (std::sqrt(1.0 - t * t) + 1.0);
    }

    /**
     * @brief Elastic easing in – exponentially accelerating with overshoot and oscillation.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @param a Amplitude of oscillation.
     * @param p Period of oscillation.
     * @return Elastic ease-in value.
     */
    static inline Float64 inElastic(Float64 t, Float64 a = 1.0, Float64 p = 0.3) noexcept {
        if (t == 0.0) return 0.0;
        if (t == 1.0) return 1.0;
        Float64 s;
        if (a < 1.0) { a = 1.0; s = p / 4.0; }
        else s = p / (2.0 * M_PI) * std::asin(1.0 / a);
        t -= 1.0;
        return -(a * std::pow(2.0, 10.0 * t) * std::sin((t - s) * (2.0 * M_PI) / p));
    }

    /**
     * @brief Elastic easing out – exponentially decelerating with overshoot and oscillation.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @param a Amplitude of oscillation.
     * @param p Period of oscillation.
     * @return Elastic ease-out value.
     */
    static inline Float64 outElastic(Float64 t, Float64 a = 1.0, Float64 p = 0.3) noexcept {
        if (t == 0.0) return 0.0;
        if (t == 1.0) return 1.0;
        Float64 s;
        if (a < 1.0) { a = 1.0; s = p / 4.0; }
        else s = p / (2.0 * M_PI) * std::asin(1.0 / a);
        return a * std::pow(2.0, -10.0 * t) * std::sin((t - s) * (2.0 * M_PI) / p) + 1.0;
    }

    /**
     * @brief Elastic easing in/out – acceleration then deceleration with oscillation.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @param a Amplitude of oscillation.
     * @param p Period of oscillation.
     * @return Elastic ease-in-out value.
     */
    static inline Float64 inOutElastic(Float64 t, Float64 a = 1.0, Float64 p = 0.45) noexcept {
        if (t == 0.0) return 0.0;
        if (t == 1.0) return 1.0;
        Float64 s;
        if (a < 1.0) { a = 1.0; s = p / 4.0; }
        else s = p / (2.0 * M_PI) * std::asin(1.0 / a);
        t *= 2.0;
        if (t < 1.0) {
            t -= 1.0;
            return -0.5 * (a * std::pow(2.0, 10.0 * t) * std::sin((t - s) * (2.0 * M_PI) / p));
        }
        t -= 1.0;
        return a * std::pow(2.0, -10.0 * t) * std::sin((t - s) * (2.0 * M_PI) / p) * 0.5 + 1.0;
    }

    /**
     * @brief Back easing in – accelerating with overshoot.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @param s Overshoot amount.
     * @return Back ease-in value.
     */
    static constexpr Float64 inBack(Float64 t, Float64 s = 1.70158) noexcept {
        return t * t * ((s + 1.0) * t - s);
    }

    /**
     * @brief Back easing out – decelerating with overshoot.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @param s Overshoot amount.
     * @return Back ease-out value.
     */
    static constexpr Float64 outBack(Float64 t, Float64 s = 1.70158) noexcept {
        t -= 1.0;
        return t * t * ((s + 1.0) * t + s) + 1.0;
    }

    /**
     * @brief Back easing in/out – acceleration and deceleration with overshoot.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @param s Overshoot amount.
     * @return Back ease-in-out value.
     */
    static constexpr Float64 inOutBack(Float64 t, Float64 s = 1.70158) noexcept {
        s *= 1.525;
        t *= 2.0;
        if (t < 1.0) return 0.5 * (t * t * ((s + 1.0) * t - s));
        t -= 2.0;
        return 0.5 * (t * t * ((s + 1.0) * t + s) + 2.0);
    }

    /**
     * @brief Bounce easing out – decelerating with bounces.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Bounce ease-out value.
     */
    static constexpr Float64 outBounce(Float64 t) noexcept {
        if (t < 1.0 / 2.75) {
            return 7.5625 * t * t;
        } else if (t < 2.0 / 2.75) {
            t -= 1.5 / 2.75;
            return 7.5625 * t * t + 0.75;
        } else if (t < 2.5 / 2.75) {
            t -= 2.25 / 2.75;
            return 7.5625 * t * t + 0.9375;
        } else {
            t -= 2.625 / 2.75;
            return 7.5625 * t * t + 0.984375;
        }
    }

    /**
     * @brief Bounce easing in – accelerating with bounces.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Bounce ease-in value.
     */
    static constexpr Float64 inBounce(Float64 t) noexcept {
        return 1.0 - outBounce(1.0 - t);
    }

    /**
     * @brief Bounce easing in/out – acceleration then deceleration with bounces.
     *
     * @param t Normalized time (0.0 to 1.0).
     * @return Bounce ease-in-out value.
     */
    static constexpr Float64 inOutBounce(Float64 t) noexcept {
        if (t < 0.5) return inBounce(t * 2.0) * 0.5;
        return outBounce(t * 2.0 - 1.0) * 0.5 + 0.5;
    }
};
