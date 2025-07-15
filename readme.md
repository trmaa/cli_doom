# cdoom

Nothing done yet, just learning and setting up the project
I do it because i want to build something using TTY only.

## Next, I will make the screen to just have methods to add shit to the pipeline and work independently. that is why it is in eng/.
## I will create json scenes or something and a file scene.c which will read them and pass them to the pipeline. this will be at src/.

Linux only

Build: 
```bash
./suckless_make.sh build
````
Run:
```bash
./cdoom
````

Build having changed the game but not the libs:
```bash
./suckless_make.sh compile_game link clean
````
