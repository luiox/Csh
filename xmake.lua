add_rules("mode.debug", "mode.release")

add_rules("plugin.compile_commands.autoupdate", { outputdir = "."})

target("csh")
    set_kind("binary")
    add_includedirs("inc")
    add_files("src/**.c")

