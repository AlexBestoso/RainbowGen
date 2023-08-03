# RainbowGen
Generate a rainbow table out of words and sentences.<br>
Compile :  `g++ main.cc -o raingen`
Usage: `./raingen 'hello world' 'prefix_' '_postfix' > rainbowTable`
<p>
The first argument will be permuted. Separate words by a space. The prefix and postfix inputs will not be permuted and can be used to generate only the unknown portions of a passphrase.
</p>
