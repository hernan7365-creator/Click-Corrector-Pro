# Click Corrector Pro — Android source prototype

**Target:** Geometry Dash Android 2.2074  
**Format:** Geode mod source project  
**Version:** 0.1.0 — uncompiled prototype

## What this prototype does

This first prototype implements a probabilistic *death-call skip*:

- `100`: skips every intercepted `PlayLayer::destroyPlayer` call.
- `50`: skips about half of those calls.
- `10`: skips about one in ten calls.
- `Enable protection`: turns the feature on or off.

## Important: what it does NOT do

This is **not true late/early click correction**. It does not move a tap backward or forward in time, predict the next input, or repair the player's trajectory. It only attempts to ignore selected calls to the game's normal death function.

Some hazards or scripted deaths may use other code paths. Skipping a death call can also leave the player overlapping an obstacle, so this prototype may behave incorrectly or crash. It must be tested and improved before anyone treats it as a working mod.

## Build requirements

You need:
- A computer (Windows, macOS, or Linux)
- Geode SDK/CLI compatible with the target game
- Android 64-bit build tools (NDK/toolchain)
- A Geometry Dash + Geode Android setup that actually runs 2.2074

The `geode` version in `mod.json` is a starting target based on a public Geode 4.7 example; adjust it to the exact Geode version installed in your build environment.

Typical Geode CLI workflow (confirm flags against your installed CLI):
```bash
cargo install geode-cli
geode sdk install
geode build -p android64 --config Release
```

The expected package is a `.geode` mod, **not a standalone APK**. Install it only through the Geode Android launcher/mods workflow for a matching game build.

## Safety / compatibility notes

- Back up your Geometry Dash save before testing mods.
- Do not install random repacked APKs or give them account credentials.
- This source has not been compiled or tested in this environment.
- An APK downloaded from a third-party site may be modified and may not be compatible with Geode.

## Next development step

Test the hook on Android 2.2074, then inspect the collision/death path so the mod can handle more than one death route. Genuine late/early input correction would require a separate input/physics design; this prototype does not claim to provide it.
