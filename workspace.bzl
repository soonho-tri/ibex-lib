# -*- python -*-
load("//tools:github.bzl", "github_archive")
def ibex_workspace():
    github_archive(
        name = "clp",
        repository = "dreal-deps/clp-1.16",
        commit = "ebf1abf25d337df1e4ba52b70a25f006c7e8b7f0",
        build_file = str(Label("//tools:clp.BUILD")),
        sha256 = "caca48340b89b377ca687580fc40a90be7b5e469a8b2caa2051bd6518052fe6e",
    )
    github_archive(
        name = "filibxx",
        repository = "dreal-deps/filibxx",
        commit = "d898fe000e157f44e4a84b8f79b4e7556a5d6fb5",
        build_file = str(Label("//tools:filibxx.BUILD")),
        sha256 = "3044c46926a216ada7ec7d8613c882840ed7c482f66878bed70d751fc70f42d4",
    )
