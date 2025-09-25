# Easing Functions (`ease.h`)

A single-header C++17 library providing a comprehensive collection of easing functions for animations, interpolation, and smooth transitions.  

Easing functions map a normalized time parameter (`t` in `[0.0, 1.0]`) into a transformed value, controlling acceleration, deceleration, bounce, and overshoot effects. They are widely used in UI animations, games, and motion design.

---

## ✨ Features
- **Header-only** (`ease.h`) – just drop it into your project.  
- **Wide variety of easing functions**:
  - Linear
  - Quadratic, Cubic, Quartic, Quintic
  - Sine, Exponential, Circular
  - Elastic, Back, Bounce
- **In, Out, InOut** variants for each type.  
- **Customizable** parameters for *Elastic* and *Back* easing.  
- **`constexpr` support** for compile-time evaluation where possible.  
- **No dependencies** beyond the C++ standard library.  

---

## 📥 Installation
Clone or copy `ease.h` into your project:

```bash
git clone https://github.com/yourusername/ease.h.git
````

Include it in your code:

```cpp
#include "ease.h"
```

No build system integration required.

---

## 🚀 Usage Example

```cpp
#include <iostream>
#include "ease.h"

int main() {
    double t = 0.3; // normalized time

    double v1 = Ease::inQuad(t);    // ease-in quadratic
    double v2 = Ease::outBounce(t); // ease-out bounce

    std::cout << "inQuad(0.3)   = " << v1 << "\n";
    std::cout << "outBounce(0.3)= " << v2 << "\n";
}
```

Output:

```
inQuad(0.3)   = 0.09
outBounce(0.3)= 0.680625
```

---

## 📚 Reference

Each function accepts a normalized time value `t ∈ [0.0, 1.0]`.

* **Linear**
  `linear(t)` – straight interpolation.

* **Quadratic / Cubic / Quartic / Quintic**
  `inQuad(t)`, `outQuad(t)`, `inOutQuad(t)` … up to `inOutQuint(t)`.

* **Sine**
  `inSine(t)`, `outSine(t)`, `inOutSine(t)`.

* **Exponential**
  `inExpo(t)`, `outExpo(t)`, `inOutExpo(t)`.

* **Circular**
  `inCirc(t)`, `outCirc(t)`, `inOutCirc(t)`.

* **Elastic** *(with amplitude `a` and period `p`)*
  `inElastic(t, a, p)`, `outElastic(t, a, p)`, `inOutElastic(t, a, p)`.

* **Back** *(with overshoot parameter `s`)*
  `inBack(t, s)`, `outBack(t, s)`, `inOutBack(t, s)`.

* **Bounce**
  `inBounce(t)`, `outBounce(t)`, `inOutBounce(t)`.

---

## 🛠 Requirements

* C++17 or newer
* A standard-compliant compiler (GCC, Clang, MSVC, etc.)

---

## 📄 License

This project is licensed under the MIT License – see [LICENSE](LICENSE) for details.
