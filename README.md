<!DOCTYPE html>
<html>
<body>

<h1>Snake Game in C</h1>

<p>A classic snake game implemented in C using the ncurses library.</p>

<h2>Description</h2>

<p>This project is a simple representation of the snake game where a player can control a snake to eat food appearing at random positions on the game board. The game is terminal-based, utilizing the ncurses library for rendering the game graphics in a terminal window.</p>

<h2>Features</h2>

<ul>
    <li>Snake movement in four directions: up, down, left, and right.</li>
    <li>Food generation at random positions (excluding borders).</li>
    <li>Collision detection with walls and self.</li>
    <li>Snake growth upon eating food.</li>
</ul>

<h2>Requirements</h2>

<ul>
    <li>GCC (or any C compiler)</li>
    <li>ncurses library</li>
    <li>Unix/Linux environment (tested on WSL)</li>
</ul>

<h2>Compilation</h2>

<p>To compile the game, navigate to the project directory and use the <code>make</code> command:</p>

<pre>
make
</pre>

<p>This will produce an executable named <code>snake_game</code>.</p>

<h2>Usage</h2>

<p>To play the game, run the compiled executable:</p>

<pre>
./snake_game
</pre>

<p>Control the snake using the arrow keys. The game ends if the snake hits the wall or collides with itself.</p>

<h2>License</h2>

<p>MIT License</p>

<h2>Acknowledgements</h2>

<p>Special thanks to the ncurses library for providing the functions to render graphics in a terminal window.</p>

</body>
</html>
