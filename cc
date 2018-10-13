#!/usr/bin/env ruby

# gcc wrapper script for ARM architecture.

def debug_log(path, command, argv)
  return if (logfile = ENV["HOMEBREW_GCC_WRAP_LOG"].to_s).empty?

  File.open(logfile, "a+") do |f|
    msg =  "[gcc-arm-wrap]: PATH = #{path.inspect}\n"
    msg << "[gcc-arm-wrap]: command = #{command.inspect}\n"
    msg << "[gcc-arm-wrap]: ARGV = #{argv.inspect}\n"
    msg << "[gcc-arm-wrap]: Execute #{command} #{argv.join(' ')}\n\n"
    f.write(msg)
  end
end

command = $0
dir = File.dirname(command); base = File.basename(command)
ccache_libexec = "#{ENV["HOMEBREW_PREFIX"]}/opt/ccache/libexec"

path = ENV["PATH"].split(":")
path.delete(dir)
path.unshift(ccache_libexec) unless path.first == ccache_libexec
ENV["PATH"] = path.join(":")

command = %x[/usr/bin/env which #{base}].chomp
ARGV.delete("-march=native"); ARGV.delete("-mcpu=native")

debug_log(path, command, ARGV)

exec command, *ARGV
