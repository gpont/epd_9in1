<h1 align="center">Welcome to epd_1in9 👋</h1>
<p>
  <a href="https://registry.platformio.org/libraries/gpont/epd_1in9" target="_blank">
    <img alt="Version" src="https://img.shields.io/badge/version-0.1.1-blue.svg?cacheSeconds=2592000" />
  </a>
  <a href="./docs/DOC.md" target="_blank">
    <img alt="Documentation" src="https://img.shields.io/badge/documentation-yes-brightgreen.svg" />
  </a>
  <a href="./LICENSE" target="_blank">
    <img alt="License: MIT" src="https://img.shields.io/badge/License-MIT-yellow.svg" />
  </a>
  <a href="https://www.paypal.me/jsheroru/100">
    <img alt="Paypal" src="https://img.shields.io/badge/$-donate-ff69b4.svg?maxAge=2592000&amp;style=flat">
  </a>
</p>

![Module](https://raw.githubusercontent.com/gpont/epd_9in1/master/docs/e-paper-module.jpg)

> EPD 1in9 eink display [waveshare](https://www.waveshare.com/product/displays/e-paper/1.9inch-segment-e-paper-module.htm) driver library for arduino.

### 🏠 [Homepage](https://registry.platformio.org/tools/gpont/epd_1in9)

## Table of Contents
- [Table of Contents](#table-of-contents)
- [Installation](#installation)
- [Usage](#usage)
- [Author](#author)
- [Contributing](#contributing)
- [Show your support](#show-your-support)
- [License](#license)

## Installation

Run command:

```sh
pio pkg install -l "gpont/epd_9in1"
```

or

On the env section of platformio.ini, add the following:

```ini
[env]
lib_deps =
  gpont/epd_9in1
```
Now the `EinkDisplay.h` is available to be included:

```cpp
#include "EinkDisplay.h"
```

## Usage

You can use high level class [EinkDisplay.h](https://github.com/gpont/epd_9in1/tree/master/include/EinkDisplay.h) or low level functions from [EPD_1in9.h](https://github.com/gpont/epd_9in1/tree/master/include/EPD_1in9.h) if your need more manual control.

Example usage:

```cpp
#include "EinkDisplay.h"

EinkDisplay *display;

void setup() {
  display = new EinkDisplay(CELSIUS);
}

void loop() {
  display->setNumbers(123.4, 12.3);
  display->setLowPowerIndicator(true);

  display->loop();
  delay(300); // For stable updating
}

```

See also:
- [Examples](https://github.com/gpont/epd_9in1/tree/master/examples) folder
- [Documentation](https://github.com/gpont/epd_9in1/tree/master/docs/DOC.md)

## Author

👤 **Evgenii Guzhikhin**

* Website: [jshero.ru](https://jshero.ru/)
* Github: [@gpont](https://github.com/gpont)
* LinkedIn: [@евгений-гужихин-274021155](https://linkedin.com/in/евгений-гужихин-274021155)

## Contributing

🤝 Contributions, issues and feature requests are welcome!<br />Feel free to check [issues page](https://github.com/gpont/epd_9in1/issues). You can also take a look at the [contributing guide](CONTRIBUTING.md).

## Show your support

Give a ⭐️ if this project helped you!

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.me/jsheroru/100)

## License

📝 Copyright © 2023 [Evgenii Guzhikhin](https://github.com/gpont).<br />
This project is [MIT](./LICENSE) licensed.
