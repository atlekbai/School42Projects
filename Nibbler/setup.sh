curl https://www.libsdl.org/release/SDL2-2.0.9.dmg -o SDL2.dmg
curl https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.4.dmg -o SDL2_image.dmg
curl https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.dmg -o SDL2_ttf.dmg
hdiutil attach SDL2.dmg
hdiutil attach SDL2_image.dmg
hdiutil attach SDL2_ttf.dmg
mkdir ./frameworks/
cp -R /Volumes/SDL2/SDL2.framework ./frameworks/
cp -R /Volumes/SDL2_image/SDL2_image.framework ./frameworks/
cp -R /Volumes/SDL2_ttf/SDL2_ttf.framework ./frameworks/
hdiutil detach /Volumes/SDL2
hdiutil detach /Volumes/SDL2_image
hdiutil detach /Volumes/SDL2_ttf
rm SDL2.dmg
rm SDL2_image.dmg
rm SDL2_ttf.dmg
