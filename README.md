# whoa-autocode

whoa-autocode is a Go tool that generates C++ class definitions based on information from the [WoWDBDefs project](https://github.com/wowdev/WoWDBDefs).

This tool is intended to provide code for the [Whoa client](https://github.com/whoahq/whoa) (which targets build 12340); however you may supply a `--build` flag to target a different build number.

It also creates `WowClientDB` instances for each of the tables. Then, a function is created, `StaticDBLoadAll`. This will load every DB table at once, with some exclusions (see autocode/nonstatic_exclusions.go)

### Install

```bash
git clone https://github.com/Gophercraft/whoa-autocode.git whoa-autocode
cd whoa-autocode
go install github.com/Gophercraft/whoa-autocode
```

### Example
```bash
whoa-autocode cpp \
	--location whoa/ \ # put Whoa project here
	--edit-warning=true \
	--normalize-members=true \
	--locale-offset-token=CURRENT_LANGUAGE
```

