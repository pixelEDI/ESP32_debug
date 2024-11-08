# ESP32(S3) Debuggen

## Linux Workaround PlatformIO und Debuggen:

Bei diversen Linux Distributionen kann es vorkommen, dass beim Debuggen Dialog ein Fehler kommt, dass eine Python2 Bibliothek nicht gefunden wird. Dafür gibt es einen Workaround

- Standard Toolchain Setup for Linux and macOS
  - https://docs.espressif.com/projects/esp-idf/en/stable/esp32s3/get-started/linux-macos-setup.html

  ESP32S3

```
mkdir ~/esp
cd ~/esp
git clone -b v5.2.2 --recursive https://github.com/espressif/esp-idf.git
cd ~/esp/esp-idf
./install.sh esp32s3
```

```
 ~/.platformio/packages/toolchain-xtensa-esp32s3/bin
mv xtensa-esp32s3-elf-gdb xtensa-esp32s3-elf-gdb.orig
cp ~/.espressif/tools/xtensa-esp-elf-gdb/14.2_20240403/xtensa-esp-elf-gdb/bin/xtensa-esp32s3-elf-gdb xtensa-esp32s3-elf-gdb
cp ~/.espressif/tools/xtensa-esp-elf-gdb/14.2_20240403/xtensa-esp-elf-gdb/bin/xtensa-esp-elf-gdb-no-python .
cp ~/.espressif/tools/xtensa-esp-elf-gdb/14.2_20240403/xtensa-esp-elf-gdb/lib/xtensa_esp32s3.so ../lib
```

Für ESP32 ist es ähnlich, ansatt esp32s3 ladet man sich die esp32 toolchain und verschiebt dementsprechend auch die esp32 anstatt esp32s3 xtensa files.

Quelle: THX arduhe https://community.platformio.org/t/debug-aborts-with-python-error/41139/3

## ESP32 mit ESP-Prog

- ESP-Prog: https://amzn.to/4hvfp7o \*
- Verdrahtung und weitere Infos: https://docs.espressif.com/projects/esp-iot-solution/en/latest/hw-reference/ESP-Prog_guide.html

> Windows Nutzer benötigen Zadiq damit ESP-Prog richtig erkannt wird
>
> - Treiber: https://ftdichip.com/drivers/vcp-drivers/
> - Siehe Abschnitt Zadig https://docs.platformio.org/en/stable/plus/debug-tools/esp-prog.html
> - https://zadig.akeo.ie/


## SeeedStudio ESP32S3

Das Debuggen funktioniert direkt via USB-C. Einstellungen wie beim Beispiel oben.

---

## OpenOCD und GDB

OpenOCD: Es stellt die Verbindung zwischen deinem Computer und dem ESP32 her. OpenOCD kommuniziert über den JTAG-Debug-Port des ESP32 und ermöglicht so das Steuern und Überwachen des Programmlaufs auf dem Mikrocontroller.

GDB: Der GNU Debugger (GDB) wird verwendet, um den Code auf dem ESP32 tatsächlich zu debuggen. Über GDB kannst du Breakpoints setzen, den Code schrittweise ausführen und Variableninhalte prüfen.

## Allgemeine Infos

- https://docs.espressif.com/projects/esp-idf/en/stable/esp32s3/get-started/linux-macos-setup.html
- https://archlinux.org/packages/extra/x86_64/openocd/
- https://wiki.debian.org/OpenOCD#Installation
- https://www.sourceware.org/gdb/bugs/


Meine Commands vom Video

- OpenOCD via Paketmanager installieren.
- `openocd -f /home/pixeledi/.espressif/tools/openocd-esp32/v0.12.0-esp32-20240821/openocd-esp32/share/openocd/scripts/board/esp32-wrover-kit-3.3v.cfg`

In einem zweiten Terminal
- GDB im Espressif Ordner: /home/pixeledi/.espressif/tools/xtensa-esp-elf-gdb/14.2_20240403/xtensa-esp-elf-gdb/bin
- ./xtensa-esp32-elf-gdb
- target extended-remote localhost:3333
- file /home/pixeledi/Downloads/esp32_debugging/.pio/build/esp32dev/firmware.elf

GDB Commands
- watch cnt
- watchpoints
- delete
- print cnt
- display cnt
- info watchpoints


* Alle Links mit "*" sind Amazon/Aliexpress Affiliate Links. Als Amazon-Partner verdiene ich an qualifizierten Verkäufen.
