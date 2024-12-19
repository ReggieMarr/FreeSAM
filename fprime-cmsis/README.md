# fprime-atmel

Add this project as a git submodule to your project, and then list the folder as a library in your settings.ini file.

Note: `fprime-atmel` also requires [`fprime-baremetal`](https://github.com/fprime-community/fprime-baremetal) for projects running F Prime v3.5.0 or later.

The following commands will add these packages as submodules:
```sh
git submodule add https://github.com/fprime-community/fprime-atmel.git
git submodule add https://github.com/fprime-community/fprime-baremetal.git
```

You can use this `settings.ini` file as a template for your F Prime project:
```.ini
[fprime]
project_root: .
framework_path: ./fprime
library_locations: ./fprime-atmel:./fprime-baremetal
config_directory: ./config
deployment_cookiecutter: https://github.com/fprime-community/fprime-atmel-deployment-cookiecutter.git

default_toolchain: teensy41

default_cmake_options:  FPRIME_ENABLE_FRAMEWORK_UTS=OFF
                        FPRIME_ENABLE_AUTOCODER_UTS=OFF
```

## Next: [Atmel CLI Installation Guide](./docs/atmel-cli-install.md)