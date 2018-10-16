class GccArmWrap < Formula
  url "https://z80oolong@bitbucket.org/z80oolong/gcc-arm-wrap.git",
    :revision => "46f96a48ed2fb4d2d03673e201682e115f7802c0"
  version "0.1"

  conflicts_with "apple-gcc42", :because => "Both install `gcc`, `g++` and etc."
  conflicts_with "gcc", :because => "Both install `gcc`, `g++` and etc."
  conflicts_with "gcc@4.9", :because => "Both install `gcc`, `g++` and etc."
  conflicts_with "gcc@5", :because => "Both install `gcc`, `g++` and etc."
  conflicts_with "gcc@6", :because => "Both install `gcc`, `g++` and etc."
  conflicts_with "gcc@7", :because => "Both install `gcc`, `g++` and etc."
  conflicts_with "gcc@8", :because => "Both install `gcc`, `g++` and etc."
  conflicts_with "homebrew/cask/gcc-arm-embedded", :because => "Both install `gcc`, `g++` and etc."

  def install
    bin.install "cc"
    bin.cd do
      system "chmod", "0755", "cc"
      (%w{c++ c++-3.3 c++-4.0 c++-4.2 c++-4.3 c++-4.4 c++-4.5 c++-4.6 c++-4.7 c++-4.8 c++-4.9 c++-5 c++-6 c++-7 c++3
          g++ g++-3.3 g++-4.0 g++-4.2 g++-4.3 g++-4.4 g++-4.5 g++-4.6 g++-4.7 g++-4.8 g++-4.9 g++-5 g++-6 g++-7 g++2 g++3
          gcc gcc-3.3 gcc-4.0 gcc-4.2 gcc-4.3 gcc-4.4 gcc-4.5 gcc-4.6 gcc-4.7 gcc-4.8 gcc-4.9 gcc-5 gcc-6 gcc-7 gcc2 gcc3}).each do |cmd|
          (system "ln", "-sf", "cc", cmd) unless %x[/usr/bin/env which #{cmd}].chomp.empty?
      end
    end
    prefix.install "README.md"
  end
end
