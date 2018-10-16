#!/usr/bin/env ruby

# The MIT License
#
# Copyright (C) 2018, NAKATSUKA, Yukitaka <zool@zool.jpn.org>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
# gcc wrapper script for ARM architecture.
# This script program removes "-march=native" and "-mcpu=native" from the gcc option.

def debug(number, path, command, argv)
  return if (logfile = ENV["HOMEBREW_GCC_WRAP_LOG"].to_s).empty?

  t = Time.now.strftime("%Y/%m/%d %H:%M:%S")

  File.open(logfile, "a+") do |f|
    msg =  "[gcc-arm-wrap (#{number}) #{t}]: PATH = #{path.inspect}\n"
    msg << "[gcc-arm-wrap (#{number}) #{t}]: command = #{command.inspect}\n"
    msg << "[gcc-arm-wrap (#{number}) #{t}]: ARGV = #{argv.inspect}\n"
    msg << "[gcc-arm-wrap (#{number}) #{t}]: Execute #{command} #{argv.join(' ')}\n\n"
    f.write(msg)
  end
end

command = $0
dir = File.dirname(command); base = File.basename(command)
ccache_libexec = "#{ENV["HOMEBREW_PREFIX"]}/opt/ccache/libexec"
path = ENV["PATH"].split(":")

debug(0, path, command, ARGV)

path.delete(dir)
if (path.first != ccache_libexec) && (ENV["HOMEBREW_USE_CCACHE"].to_s == "1")
  path.unshift(ccache_libexec)
end
ENV["PATH"] = path.join(":")

command = %x[/usr/bin/env which #{base}].chomp
ARGV.delete("-march=native"); ARGV.delete("-mcpu=native")

debug(1, path, command, ARGV)

exec command, *ARGV
