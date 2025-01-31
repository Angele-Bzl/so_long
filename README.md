# So_long
## and thanks for all the dogs !
*This project was a first step into graphic display and use of the `minilibx` [(mlx)](https://harm-smits.github.io/42docs/libs/minilibx/introduction.html) library, that allows to do basic rendering on screens.*

![screenshot of the game where you can see the player and few dogs to save from the shelter](https://i.ibb.co/V08MBNzK/Screenshot-from-2025-01-31-13-17-47.png)

Welcome to my first project with graphics. In this program (or dare I call it, this game) you will impersonate a hero that sneaked into a shelter to save all the dogs.
The rules are simple, you can't leave as long as you didn't get all the dogs.
Once every dog is saved from this prison, you can leave.

### how to use the program
- git clone the repository
- `make`
- `./so_long maps/fun.ber`
- when you are over you can delete the executable with `make fclean`
In the first time you can try this program with the maps `fun.ber` or `default.ber` but feel free to create your own map to test it on (and enjoy my map parsing)
**If you want to create your own map**
  - One player, no more, no less
  - One exit, no more, no less
  - Surrounded by walls
  - At least one dog
  - Finishable
  - Rectangle

### What I liked about this project
- It was the first time that I had to work with an **external library** (apart from very classic ones like `stdio` or `unistd`) so there was a lot to learn about digging inside someone else's code, especially to make sure there were no leaks
- Doing a graphical projet was satisfying and helped working more efficiently because I easly had a **visual feedback** on my code thanks to the displayed window.
- Despite the simplicity of the game, with hooks this program asks the user to **interact** with it and makes it satisfying.
- Dogs !

### Skills
- Memory leaks checking
- Excellent drawings
- Minilibx
- C
