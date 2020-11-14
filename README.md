# C++ for Rustaceans

Navigate to https://tianyishi2001.github.io/cpp4r to read online. Alternatively, you can download the [PDF](https://tianyishi2001.github.io/cpp4r/cpp4r.pdf) or [epub](https://tianyishi2001.github.io/cpp4r/cpp4r.epub) formats.


# About this Book

I'm a biochemistry student wishing to specialize in computational biology, and I need a fast (specifically, no-GC) language for implementing algorithms. Since the decision was made in April 2020, I naturally chose Rust. Soon I fell in love with it. Cargo, rustdoc, crates.io, clippy etc. just makes Rust so nice--even better than Python. However, I have to face the reality: the majority of bioinformatics algorithms to date are written in C or C++ (either as pure C or C++ libraries or as extensions to Python or R), and most labs are still developing on them. It turns out that some C and C++ literacy is necessary for me.

While there is a project called [r4cppp](https://github.com/nrc/r4cppp) that introduces Rust to C++ programmers, I haven't found any cpp4r, so I started this one. I'm not an expert in Rust and C++ and I'm writing this book while learning them, so it'll be more like a personal notebook than a perfessional guide. I'll try to make it readable, though.

# Contributing

- **Typos and grammar mistakes**. English is not my native language, so I make mistakes often. If you find one I would be grateful if you could submit an issue or PR to correct it.
- **Conceptual mistakes on Rust or C++**. I'm not a professional programmer

# Building The Book

You should be familiar with [Bookdown](https://bookdown.org/). The book can be easily build using RStudio. Since it's a bit complicated for people who don't use R and RStudio, I recommend just reading it online or download the PDF. You're free to copy the markdown files and render them with other tools. However, note that these markdown files are not regualr ones. They are Rmarkdown files, which are basically pandoc markdown + R integration.

If you want to build the book in RStudio, there are some prerequisites:

- The Font 'Source Han Serif' is used for CJK characters in LaTeX output. This font can be downloaded from https://github.com/adobe-fonts/source-han-serif